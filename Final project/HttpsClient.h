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
    Link _link;
    std::string _port;
    int _httpVersion; 
    net::io_context _ioc;
    ssl::context _ctx;
    tcp::resolver _resolver;
    ssl::stream<beast::tcp_stream> _stream;
    std::string _html_body;
};
