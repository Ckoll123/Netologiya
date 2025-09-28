#include "DBcontrol.h"

DBcontrol::DBcontrol(std::string conectionSetup) :
    c(conectionSetup),
    tableCites("Cites"),
    tableWords("Words"),
    tableCites_Words("Cites_Words")
{}

void DBcontrol::createTables(){
    pqxx::work tx(c);
    std::string sqlRequest{"CREATE TABLE IF NOT EXISTS " + 
                            tx.quote_name(tableCites) +
                            " (id SERIAL PRIMARY KEY, cite TEXT UNIQUE NOT NULL)"};
    tx.exec(sqlRequest);

    sqlRequest = "CREATE TABLE IF NOT EXISTS " + 
                            tx.quote_name(tableWords) +
                            " (id SERIAL PRIMARY KEY, word TEXT UNIQUE NOT NULL)";
    tx.exec(sqlRequest);

    sqlRequest = "CREATE TABLE IF NOT EXISTS " +
                            tx.quote_name(tableCites_Words) +
                            " (cite_id INTEGER NOT NULL REFERENCES " + tx.quote_name(tableCites) + "(id), "
                            "word_id INTEGER NOT NULL REFERENCES " + tx.quote_name(tableWords) + "(id), "
                            "word_count INTEGER NOT NULL DEFAULT 1, "
                            "PRIMARY KEY (cite_id, word_id))";
    tx.exec(sqlRequest);
    tx.commit();
}

void DBcontrol::updateDB(const std::string& citeName, const std::map<std::string, int>& wordCountMap){
    pqxx::work tx(c);
    int cite_id;

    std::string sqlRequest{"INSERT INTO " + tx.quote_name(tableCites) + " (cite) VALUES ($1) " +
                            "ON CONFLICT (cite) DO UPDATE SET cite = EXCLUDED.cite "
                            "RETURNING id"};
    pqxx::result result = tx.exec_params(sqlRequest, citeName);
    cite_id = result[0][0].as<int>();

    for (const auto& [word, word_count] : wordCountMap) {
        int word_id;

        // Вставляем слово (или берём существующее)
        std::string sqlRequest{"INSERT INTO " + tx.quote_name(tableWords) + " (word) VALUES ($1) "
                                "ON CONFLICT (word) DO UPDATE SET word = EXCLUDED.word "
                                "RETURNING id"};
        pqxx::result r = tx.exec_params(sqlRequest, word);
        word_id = r[0][0].as<int>();

        // Вставляем связь документ-слово
        sqlRequest = "INSERT INTO " + tx.quote_name(tableCites_Words) + " (cite_id, word_id, word_count ) "
                     "VALUES ($1, $2, $3) "
                     "ON CONFLICT (cite_id, word_id) DO UPDATE "
                     "SET word_count = EXCLUDED.word_count ";
        tx.exec_params(sqlRequest, cite_id, word_id, word_count);
    }

    tx.commit();
}

// void DBcontrol::addClient(std::string name, std::string surname, std::string email){
//     pqxx::work tx( c );
//     std::string sqlRequest{"INSERT INTO " + tableName + " (name, surname, email) VALUES('" + 
//                             tx.esc(name) + "', '" + 
//                             tx.esc(surname) + "', '" +
//                             tx.esc(email) + "')"};
//     tx.exec(sqlRequest);
//     tx.commit();
// }


// void DBcontrol::addClientPhone(size_t id, std::string phone){
//     pqxx::work tx( c );
//     std::string sqlRequest{"UPDATE " + tableName + " SET phoneNumber='" + tx.esc(phone) + "' WHERE id=" + tx.quote(id)};
//     tx.exec(sqlRequest);
//     tx.commit();
// }


// void DBcontrol::changeClientData(size_t id, std::string name, std::string surname, std::string email, std::string phone){
//     pqxx::work tx( c );
//     std::string sqlRequest{"UPDATE " + tableName +
//                             " SET name = '" + tx.esc(name) + 
//                             "', surname = '" + tx.esc(surname) + 
//                             "', email='" + tx.esc(email) + 
//                             "', phoneNumber='" + tx.esc(phone) + 
//                             "' WHERE id=" + tx.quote(id)};
//     tx.exec(sqlRequest);
//     tx.commit();
// }



// void DBcontrol::removeClientPhone(size_t id){
//     pqxx::work tx( c );
//     std::string sqlRequest{"UPDATE " + tableName + " SET phoneNumber=NULL WHERE id=" + tx.quote(id)};
//     tx.exec(sqlRequest);
//     tx.commit();
// }


// void DBcontrol::removeClient(size_t id){
//     pqxx::work tx( c );
//     std::string sqlRequest{"DELETE FROM " + tableName + " WHERE id=" + tx.quote(id)};
//     tx.exec(sqlRequest);
//     tx.commit();
// }


// void DBcontrol::findClient(std::string name, std::string surname, std::string email, std::string phone){
//     pqxx::work tx( c );
//     std::string sqlRequest{"SELECT id, name FROM " + tableName +
//                             " WHERE name ILIKE " + tx.quote(name) + 
//                             " OR surname ILIKE " + tx.quote(surname) + 
//                             " OR email ILIKE " + tx.quote(email) + 
//                             " OR phoneNumber ILIKE " + tx.quote(phone)};
//     for (auto [id, name] : tx.query<std::string, std::string>(sqlRequest))
//     {
//         std::cout << id << " - client id and name is " << name << ".\n";
//     }
// }