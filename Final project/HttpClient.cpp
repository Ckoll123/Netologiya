#include "HttpClient.h"


HttpClient::HttpClient() :
    _link(),
    _port(),
    _httpVersion(10),
    _ioc(),
    _resolver(_ioc),
    _stream(_ioc),
    _html_body()
{}


void HttpClient::setConnectionParams(const Link& link, std::string port, int httpVersion){
    _link = link;
    _port = port;
    _httpVersion = httpVersion;
}


void HttpClient::sendGetRequest(){
    try{
        // Look up the domain name
        auto const results = _resolver.resolve(_link.host, _port);

        // Make the connection on the IP address we get from a lookup
        _stream.connect(results);

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
        _html_body = beast::buffers_to_string(res.body().data());

        // Write the message to standard out
        std::cout << res.base() << std::endl;

        // Gracefully close the socket
        beast::error_code ec;
        _stream.socket().shutdown(tcp::socket::shutdown_both, ec);

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


std::pair<Link, std::string> HttpClient::returnDataForIndexer() const{
    return { _link, _html_body };
}
