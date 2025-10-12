#include "HttpsClient.h"


HttpsClient::HttpsClient() :
    _link(),
    _port(),
    _httpVersion(11),
    _ioc(),
    _ctx(ssl::context::tlsv12_client),
    _resolver(_ioc),
    _html_body()
{
    // load_root_certificates(_ctx);

    std::filesystem::path cacertPath = std::filesystem::current_path() / "cacert.pem";

    if (std::filesystem::exists(cacertPath)) {
        _ctx.load_verify_file(cacertPath.string());
        std::cout << "[HTTPS] Loaded local cacert.pem\n";
    } else {
        std::cerr << "[HTTPS] Warning: cacert.pem not found, trying system default\n";
        _ctx.set_default_verify_paths();
    }

    // _ctx.set_default_verify_paths();
    _ctx.set_verify_mode(ssl::verify_peer);
    // _ctx.set_verify_mode(ssl::verify_none);
}


void HttpsClient::setConnectionParams(const Link& link, std::string port, int httpVersion){
    _link = link;
    _port = port;
    _httpVersion = httpVersion;
}


void HttpsClient::sendGetRequest(){
    try{
        ssl::stream<beast::tcp_stream> _stream(_ioc, _ctx);
        std::cout << "[HTTPS] start request for: " + _link.host + _link.target + "\n";

        connect(_stream);
        setupTLS(_stream);
        sendRequest(_stream);

        auto res = readResponse(_stream);
        if (res.result() == http::status::unknown) { return; }

        if (handleRedirect(res, _stream)) { return; }
     
        processBody(res);
        shutdown(_stream);
    }
    catch(std::exception const& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


void HttpsClient::setupTLS(ssl::stream<beast::tcp_stream>& stream) {
    if(!SSL_set_tlsext_host_name(stream.native_handle(), _link.host.c_str())) {
        beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
        throw beast::system_error{ec};
    }

    stream.handshake(ssl::stream_base::client);
    std::cout << "[HTTPS] TLS handshake ok" << std::endl;
}


void HttpsClient::connect(ssl::stream<beast::tcp_stream>& stream) {
    // Look up the domain name
    auto const results = _resolver.resolve(_link.host, _port);
    std::cout << "[HTTPS] resolve ok, endpoints: " << results.begin()->endpoint() << std::endl;

    // Make the connection on the IP address we get from a lookup
    beast::get_lowest_layer(stream).connect(results);
    std::cout << "[HTTPS] connect ok" << std::endl;
}


void HttpsClient::sendRequest(ssl::stream<beast::tcp_stream>& stream) {
    // Set up an HTTP GET request message
    http::request<http::string_body> req{http::verb::get, _link.target, _httpVersion};
    req.set(http::field::host, _link.host);
    req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

    // Send the HTTP request to the remote host
    http::write(stream, req);
    std::cout << "[HTTPS] request written" << std::endl;
}



http::response<http::dynamic_body> HttpsClient::readResponse(ssl::stream<beast::tcp_stream>& stream){
    beast::flat_buffer buffer;
    beast::error_code ec_read;
    http::response_parser<http::dynamic_body> parser;

    // Чтение заголовков
    http::read_header(stream, buffer, parser, ec_read);
    if (ec_read && ec_read != boost::asio::ssl::error::stream_truncated) {
        std::cerr << "[HTTPS] read_header failed: " << ec_read.message() << "\n";
        return {};
    }

    // Чтение тела (чанков)
    while (!parser.is_done()) {
        http::read_some(stream, buffer, parser, ec_read);
        if (ec_read) {
            if (ec_read == boost::asio::ssl::error::stream_truncated) {
                std::cerr << "[HTTPS] stream_truncated while reading body — using partial data\n";
                ec_read = {};
                break;
            } else {
                std::cerr << "[HTTPS] http::read_some failed: " << ec_read.message() << "\n";
                return {};
            }
        }
    }

    return parser.get();
}


bool HttpsClient::handleRedirect(const http::response<http::dynamic_body>& res, ssl::stream<beast::tcp_stream>& stream){
    if (res.result_int() / 100 != 3)
        return false;

    auto loc = res[http::field::location];
    if (loc.empty())
        return false;

    std::cout << "[HTTPS] Redirect to: " << loc << std::endl;

    
    auto [newHost, newTarget] = [](const Link& oldLink, boost::beast::string_view& url) {
        std::string host;
        std::string target;

        size_t protocol_end = url.find("://");
        if (protocol_end == std::string::npos) {
            host = oldLink.host;
            target = url;
            return std::make_pair(host, target);
        }
        protocol_end += 3;

        size_t slash_pos = url.find('/', protocol_end);
        if (slash_pos == std::string::npos) {
            host = url.substr(protocol_end);
            target = "/";
        } else {
            host = url.substr(protocol_end, slash_pos - protocol_end);
            target = url.substr(slash_pos);
        }

        return std::make_pair(host, target);
    }(_link, loc);

    
    beast::error_code ec;
    stream.shutdown(ec);
    if (ec == net::error::eof || ec == boost::asio::ssl::error::stream_truncated) { ec = {}; }
    if (ec && ec != beast::errc::not_connected) { throw beast::system_error{ec}; }

    _link = Link({ newHost, newTarget }, _link.currentRecursionDepth);
    sendGetRequest();

    return true;
}

void HttpsClient::processBody(const http::response<http::dynamic_body>& res) {
    auto contentType = res[http::field::content_type];

    if (contentType.find("text/html") != std::string::npos) {
        _html_body = beast::buffers_to_string(res.body().data());
    } else {
        _html_body = "Not html";
    }

    std::cout << "Link address: " + _link.host + _link.target + "\n"
              + "Link depth: " + std::to_string(_link.currentRecursionDepth) + "\n"
              << std::endl;
}


void HttpsClient::shutdown(ssl::stream<beast::tcp_stream>& stream) {
    // Gracefully close the socket
    beast::error_code ec;
    stream.shutdown(ec);

    // not_connected happens sometimes
    // so don't bother reporting it.
    if (ec == net::error::eof || ec == boost::asio::ssl::error::stream_truncated)
        ec = {};
    if (ec && ec != beast::errc::not_connected)
        throw beast::system_error{ec};

    // If we get here then the connection is closed gracefully
}



std::pair<Link, std::string> HttpsClient::returnDataForIndexer() const{
    return { _link, _html_body };
}
