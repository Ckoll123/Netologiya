#include <iostream>
#include <stdexcept>
#include <fstream>
#include <pqxx/pqxx>

#include "IniParser.h"
#include "DBcontrol.h"
#include "Indexer.h"
#include "HttpClient.h"

#include "ThreadPool.h"

int main(){

    try{
        IniParser parser("configurator.ini");
        auto start_page = parser.get_value<std::string>("Spider.start_page");
        auto recursion_depth = parser.get_value<int>("Spider.recursion_depth");
        auto server_port = parser.get_value<int>("Server.port");

        auto db_host = parser.get_value<std::string>("DB.host");
        auto port_port = parser.get_value<std::string>("DB.port");
        auto db_name = parser.get_value<std::string>("DB.db_name");
        auto db_user = parser.get_value<std::string>("DB.user");
        auto db_password = parser.get_value<std::string>("DB.password");

        std::string connectionSetup {
            "host=" + db_host + " "
            "port=" + port_port + " "
            "dbname=" + db_name + " "
            "user=" + db_user + " "
            "password=" + db_password + " "
        };

        DBcontrol DB(connectionSetup);
        DB.createTables();
        ThreadPool threadPool(std::thread::hardware_concurrency() - 1, &DB);
        threadPool.submit({start_page, "/"});

        {
            // Indexer indexer;
            // HttpClient client;
            // client.setConnectionParams("httpbin.org", "80", "/");   // в очередь должна класться первоначальная страница
            // client.sendGetRequest();
            // indexer.indexPage(client.returnDataForIndexer());
            // indexer.sendDataToDB(DB);

            // while(!indexer.isAllPagesIndexed()){    // это все, в одном потоке
            //     std::pair<std::string, std::string> url = indexer.getLink(); // должна и очереди браться
            //     client.setConnectionParams(url.first, "80", url.second);
            //     client.sendGetRequest();
            //     indexer.indexPage(client.returnDataForIndexer());
            //     indexer.sendDataToDB(DB);
            // }
            // // должен быть метод у основного потока, который будет забирать links и класть их в очередь
        }

    }
    catch(const std::out_of_range& ex){
        std::cout << ex.what() << std::endl;
        // std::cout << "Не существует указанной секции или переменной" << std::endl;
    }
    catch (pqxx::sql_error e){
        std::cout << e.what() << std::endl;
    }
    catch(const std::exception& ex){
        std::cout << ex.what() << std::endl;
    }




    return 0;
}
