#include <string>
#include <vector>
#include <map>

using namespace std;

struct SqlRequest{
    vector<string> columns;
    string fromTableName;
    // vector<pair<string, string>> whereParams;
    map<string, string> whereParams;
};

class SqlSelectQueryBuilder{
public:
    SqlSelectQueryBuilder& AddColumn(const string& name);
    void AddFrom(const string& tableName);
    SqlSelectQueryBuilder& AddWhere(const string& key, const string& value);
    
    SqlSelectQueryBuilder& AddWhere(const map<string, string>& kv) noexcept;
    SqlSelectQueryBuilder& AddColumns(const vector<string>& columns) noexcept;
    
    virtual string BuildQuery();

protected: 
    SqlRequest _sql_request;
};


class AdvancedSqlSelectQueryBuilder : public SqlSelectQueryBuilder{
public:
    void AddOperator(char op);
    string BuildQuery() override;
private:
    char _opWhere{'='};
};