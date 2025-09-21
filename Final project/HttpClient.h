#pragma once

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
// #include <vector>

#include "Link.h"

namespace beast = boost::beast;     // from <boost/beast.hpp>
namespace http = beast::http;       // from <boost/beast/http.hpp>
namespace net = boost::asio;        // from <boost/asio.hpp>
using tcp = net::ip::tcp;           // from <boost/asio/ip/tcp.hpp>



class HttpClient{
public:
    HttpClient();
    // void setConnectionParams(std::string host, std::string port, std::string target, int httpVersion = 10);
    void setConnectionParams(const Link& link, std::string port, int httpVersion = 10);
    void sendGetRequest();
    // std::vector<std::string> returnDataForIndexer() const;
    std::pair<Link, std::string> returnDataForIndexer() const;

private:
    Link _link;
    std::string _port;
    int _httpVersion; 
    net::io_context _ioc;
    tcp::resolver _resolver;
    beast::tcp_stream _stream;
    std::string _html_body;
};
