#include <iostream>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <pqxx/pqxx>

#include "IniParser.h"
#include "BDcontrol.h"

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

        // std::cout << "Значение в Section10.var1 = " << db_host << std::endl;
        // std::cout << "Значение в Section10.var1 = " << port_port << std::endl;
        // std::cout << "Значение в Section10.var1 = " << db_name << std::endl;
        // std::cout << "Значение в Section10.var1 = " << db_user << std::endl;
        // std::cout << "Значение в Section10.var1 = " << db_password << std::endl;

        std::string connectionSetup {
            "host=" + db_host + " "
            "port=" + port_port + " "
            "dbname=" + db_name + " "
            "user=" + db_user + " "
            "password=" + db_password + " "
        };

        BDcontrol bd(connectionSetup);
        bd.createTable("Documents");
        bd.createTable("Words");
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


    // try{
        // std::string connectionSetup {
        //     "host=localhost "
        //     "port=5432 "
        //     "dbname=postgres "
        //     "user=admin "
        //     "password=12345"
        // };

        // BDcontrol bd(connectionSetup);
        // bd.createTable("Documents");
        // bd.createTable("Words");
        // bd.addClient("Joe", "Bon", "Joe@email.com");
        // bd.addClientPhone(1, "12345");
        // bd.changeClientData(1, "Joe", "Bon", "Joe@email.com", "54321");
        // bd.removeClientPhone(1);
        // bd.removeClient(1);
        // bd.findClient("Joe", "Bon", "", "");
    // }
    // catch (pqxx::sql_error e){
    //     std::cout << e.what() << std::endl;
    // }
    // catch (std::exception e){
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}
