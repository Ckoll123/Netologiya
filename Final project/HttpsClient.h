#pragma once

#include "root_certificates.hpp"

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/ssl/error.hpp>
#include <boost/asio/ssl/stream.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <filesystem>

#include "Link.h"

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
namespace ssl = net::ssl;       // from <boost/asio/ssl.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>



class HttpsClient{
public:
    HttpsClient();
    void setConnectionParams(const Link& link, std::string port, int httpVersion = 10);
    void sendGetRequest();
    std::pair<Link, std::string> returnDataForIndexer() const;

private:
    void setupTLS(ssl::stream<beast::tcp_stream>& stream);
    void connect(ssl::stream<beast::tcp_stream>& stream);
    void sendRequest(ssl::stream<beast::tcp_stream>& stream);
    http::response<http::dynamic_body> readResponse(ssl::stream<beast::tcp_stream>& stream);
    bool handleRedirect(const http::response<http::dynamic_body>& res, ssl::stream<beast::tcp_stream>& stream);
    void processBody(const http::response<http::dynamic_body>& res);
    void shutdown(ssl::stream<beast::tcp_stream>& stream);

private:
    Link _link;
    std::string _port;
    int _httpVersion; 
    net::io_context _ioc;
    ssl::context _ctx;
    tcp::resolver _resolver;
    std::string _html_body;
};
