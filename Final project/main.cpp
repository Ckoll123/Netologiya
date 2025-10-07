#include <iostream>
#include <stdexcept>
#include <fstream>
#include <pqxx/pqxx>

#include "DBcontrol.h"
#include "IniParser.h"
#include "Indexer.h"
#include "HttpsClient.h"
#include "HttpServer.h"
#include "ThreadPool.h"


#ifndef DOC_ROOT
#define DOC_ROOT "server_data"
#endif

int main(){

    try{
        IniParser parser("configurator.ini");
        auto startPage = parser.get_value<std::string>("Spider.start_page");
        size_t recursionDepth = parser.get_value<int>("Spider.recursion_depth");
        auto serverPort = parser.get_value<int>("Server.port");

        auto dbHost = parser.get_value<std::string>("DB.host");
        auto dbPort = parser.get_value<std::string>("DB.port");
        auto dbName = parser.get_value<std::string>("DB.db_name");
        auto dbUser = parser.get_value<std::string>("DB.user");
        auto dbPassword = parser.get_value<std::string>("DB.password");

        std::string connectionSetup {
            "host=" + dbHost + " "
            "port=" + dbPort + " "
            "dbname=" + dbName + " "
            "user=" + dbUser + " "
            "password=" + dbPassword + " "
            "sslmode=disable"
        };

        Link startLink( {startPage, "/wiki/Main_Page"}, 1 );

        DBcontrol db(connectionSetup);
        db.createTables();
        ThreadPool threadPool(std::thread::hardware_concurrency() - 1, &db, recursionDepth);
        threadPool.submit(startLink);

        HttpServer server(std::string("0.0.0.0"), std::string("8080"), DOC_ROOT, db);
        server.execute();

    }
    catch(const std::out_of_range& ex){
        std::cerr << ex.what() << std::endl;
        // std::cerr << "Не существует указанной секции или переменной" << std::endl;
    }
    catch (pqxx::sql_error ex){
        std::cerr << ex.what() << std::endl;
    }
    catch(const std::exception& ex){
        std::cerr << "Error: " << ex.what() << std::endl;
        return EXIT_FAILURE;
    }

    return 0;
}
