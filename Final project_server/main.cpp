//
// Copyright (c) 2016-2019 Vinnie Falco (vinnie dot falco at gmail dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
// Official repository: https://github.com/boostorg/beast
//

//------------------------------------------------------------------------------
//
// Example: HTTP server, synchronous
//
//------------------------------------------------------------------------------

#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/config.hpp>
#include <boost/algorithm/string.hpp>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <fstream>
#include <sstream>

#include "DBcontrol.h"
#include "HttpServer.h"


std::string connectionSetup {
    "host=127.0.0.1 "
    "port=6000 "
    "dbname=final_project_db "
    "user=admin "
    "password=password"
};

DBcontrol db(connectionSetup);


#ifndef DOC_ROOT
#define DOC_ROOT "server_data"
#endif

int main()
{
    try
    {
        HttpServer server(std::string("0.0.0.0"), std::string("8080"), DOC_ROOT, db);
        server.execute();
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}


