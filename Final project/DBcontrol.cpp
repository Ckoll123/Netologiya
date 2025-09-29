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

std::vector<std::string> DBcontrol::querryProcessing(std::vector<std::string> words){
    pqxx::work tx(c);

    std::string sqlRequest{"WITH query_words AS ( "
                           "SELECT DISTINCT id "
                           "FROM \"Words\" "
                           "WHERE word IN ("};

    for (size_t i = 0; i < words.size(); ++i) {
        sqlRequest += tx.quote(words[i]);
        if (i + 1 < words.size()) sqlRequest += ",";
    }

    sqlRequest +=   ") "
                    "), "
                    "words_count AS ( "
                    "SELECT "
                        "cw.cite_id, "
                        "SUM(cw.word_count) AS total_count "
                        "FROM \"Cites_Words\" cw "
                        "JOIN query_words qw ON cw.word_id = qw.id "
                        "GROUP BY cw.cite_id "
                    ") "
                    "SELECT "
                        // "c.id AS cite_id, "
                        "c.cite AS cite_text "
                        // "wc.total_count "
                    "FROM words_count wc "
                    "JOIN \"Cites\" c ON c.id = wc.cite_id "
                    "ORDER BY wc.total_count DESC "
                    "LIMIT 10; ";

    // std::cout << "SQL: " << sqlRequest << "\n";

    pqxx::result r = tx.exec(sqlRequest);
    std::vector<std::string> result;
    for (auto row : r) {
        // int id = row[0].as<int>();
        // std::string citeName = row[1].as<std::string>();
        // int totalCount = row[2].as<int>();

        //     std::cout << id << " - cite id and cite name is " << citeName
        //               << " with total words count = " << totalCount << ".\n";
        
        result.emplace_back(row[0].as<std::string>());
    }

    return std::move(result);
}
