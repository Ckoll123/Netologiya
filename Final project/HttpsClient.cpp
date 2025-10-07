#include "HttpsClient.h"


HttpsClient::HttpsClient() :
    _link(),
    _port(),
    _httpVersion(10),
    _ioc(),
    _ctx(ssl::context::tlsv12_client),
    _resolver(_ioc),
    _stream(_ioc, _ctx),
    _html_body()
{
    load_root_certificates(_ctx);
    _ctx.set_verify_mode(ssl::verify_peer);
}


void HttpsClient::setConnectionParams(const Link& link, std::string port, int httpVersion){
    _link = link;
    _port = port;
    _httpVersion = httpVersion;
}


void HttpsClient::sendGetRequest(){
    try{
        // _stream = ssl::stream<tcp::socket>(_ioc, _ctx);

        if(!SSL_set_tlsext_host_name(_stream.native_handle(), _link.host.c_str()))
        {
            beast::error_code ec{static_cast<int>(::ERR_get_error()), net::error::get_ssl_category()};
            throw beast::system_error{ec};
        }

        // Look up the domain name
        auto const results = _resolver.resolve(_link.host, _port);

        // Make the connection on the IP address we get from a lookup
        // _stream.connect(results);
        beast::get_lowest_layer(_stream).connect(results);
        _stream.handshake(ssl::stream_base::client);

        // Set up an HTTP GET request message
        http::request<http::string_body> req{http::verb::get, _link.target, _httpVersion};
        req.set(http::field::host, _link.host);
        req.set(http::field::user_agent, BOOST_BEAST_VERSION_STRING);

        // Send the HTTP request to the remote host
        http::write(_stream, req);

        // This buffer is used for reading and must be persisted
        beast::flat_buffer buffer;

        // Declare a container to hold the response
        http::response<http::dynamic_body> res;

        // Receive the HTTP response
        http::read(_stream, buffer, res);

        auto contentType = res[http::field::content_type];
        if (contentType.find("text/html") != std::string::npos) {
            _html_body = beast::buffers_to_string(res.body().data());
        }
        else{
            _html_body = "Not html";
        }

        // Write the message to standard out
        std::cout << res.base() << std::endl;
        std::cout << "Link address: " + _link.host + _link.target + "\n"
                  + "Link depth: " + std::to_string(_link.currentRecursionDepth) + "\n" << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        // _stream.socket().shutdown(tcp::socket::shutdown_both, ec);
        // beast::get_lowest_layer(_stream).socket().shutdown(tcp::socket::shutdown_both, ec);
        _stream.shutdown(ec);

        // not_connected happens sometimes
        // so don't bother reporting it.
        //
        if(ec && ec != beast::errc::not_connected)
            throw beast::system_error{ec};

        // If we get here then the connection is closed gracefully
    }
    catch(std::exception const& e){
        std::cerr << "Error: " << e.what() << std::endl;
    }
}


std::pair<Link, std::string> HttpsClient::returnDataForIndexer() const{
    return { _link, _html_body };
}
