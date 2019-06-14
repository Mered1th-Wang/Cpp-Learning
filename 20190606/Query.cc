#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <set>
#include <map>
#include <sstream>
#include <cmath>
#include <fstream>

using namespace std;
using line_no = vector<string>::size_type;


string make_plural(size_t ctr, const string & word, const string& ending)
{
    return (ctr == 1) ? word : word + ending;
}

class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file; //每行字符串信息
    map<string, shared_ptr<set<line_no>>> wm; //每个单词到对应的行号集合的映射
};

TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while(getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while(line >> word){
            auto &lines = wm[word]; //lines是word对应的shared_ptr
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

class QueryResult
{
  friend ostream& print(ostream&, const QueryResult&);
public:
  QueryResult(string s, 
              shared_ptr<set<line_no>> p, 
              shared_ptr<vector<string>> f):
    sought(s), lines(p), file(f) {}

private:
  string sought; //查询单词
  shared_ptr<set<line_no>> lines; //出现的行号
  shared_ptr<vector<string>> file; //每行字符串信息
};

QueryResult TextQuery::query(const string &sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if(loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // 如果找到了单词，打印出现次数和所有出现的位置
    os << qr.sought << " occurs " << qr.lines->size() << " "
        << make_plural(qr.lines->size(), "time", "s") << endl;
}

class Query_base
{
    friend class Query;
protected:
    virtual ~Query_base() = default;
private:
    virtual QueryResult eval(const TextQuery&) const = 0;
    virtual string rep() const = 0;
};

class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query&, const Query&);
    friend Query operator&(const Query&, const Query&);
public:
    Query(const string&);
    QueryResult eval(const TextQuery &t) const
    { return q->eval(t); }
    string rep() const { return q->rep(); }
private:
    Query(shared_ptr<Query_base> query): q(query) {}
    shared_ptr<Query_base> q;
};

ostream &
operator<<(ostream &os, const Query &query)
{
    return os << query.rep();
}



int main()
{
    
    return 0;
}
