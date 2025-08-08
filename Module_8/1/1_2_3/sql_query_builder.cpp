#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const string& name){
    _sql_request.columns.emplace_back(name);
    return *this;
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumns(const vector<string>& columns) noexcept{
    for (const string& element : columns){
        _sql_request.columns.emplace_back(element);
    }
    return *this;
}


void SqlSelectQueryBuilder::AddFrom(const string& tableName){
    _sql_request.fromTableName = tableName;
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const string& key, const string& value){
    _sql_request.whereParams[key] = value;
    return *this;
}


SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::map<std::string, std::string>& kv) noexcept{
    for (const auto& [key, value] : kv) {
        _sql_request.whereParams[key] = value;
    }
    return *this;
}


string SqlSelectQueryBuilder::BuildQuery(){
    string result{"SELECT "};
    
    if (_sql_request.columns.empty()){
        result += '*';
    }
    else{
        string sep;
        for (const string& element : _sql_request.columns){
            result += sep + element;
            sep = ", ";
        }
    }

    result += " FROM ";
    result += _sql_request.fromTableName + " WHERE ";

    {
        string sep;
        for (const auto& element : _sql_request.whereParams){
            result += sep + element.first  + '=' + element.second;
            sep = " AND ";
        }
    }

    result += ';';

    return result;
}


void AdvancedSqlSelectQueryBuilder::AddOperator(char op){
    _opWhere = op;
}


string AdvancedSqlSelectQueryBuilder::BuildQuery(){
    string result{"SELECT "};
    
    if (_sql_request.columns.empty()){
        result += '*';
    }
    else{
        string sep;
        for (const string& element : _sql_request.columns){
            result += sep + element;
            sep = ", ";
        }
    }

    result += " FROM ";
    result += _sql_request.fromTableName + " WHERE ";

    {
        string sep;
        for (const auto& element : _sql_request.whereParams){
            result += sep + element.first  + _opWhere + element.second;
            sep = " AND ";
        }
    }

    result += ';';

    return result;
}