#include <iostream>
#include <stdexcept>
#include <fstream>
#include <pqxx/pqxx>

#include "IniParser.h"
#include "DBcontrol.h"
#include "Indexer.h"

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

        Indexer indexer;
        indexer.indexPage("start_page.html");
        indexer.sendDataToDB(DB);
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
