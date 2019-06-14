#include <cctype>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

class TextQuery
{
public:
    TextQuery(ifstream&);
    QueryResult query(const string&) const;

    void readFile(const string filename)
    {
        ifstream ifs(filename);
        string line;
        int LineCount = 1;
        while(getline(ifs, line))
        {
            lines.insert(pair<int, string>(LineCount, line));
            ++LineCount;
        }
        func();
        ifs.close();
    }
    QueryResult query(const string filename&) const;
    {
        string line, word;
        for(auto &x : lines)
        {
            istringstream record(x.second);
            while(record >> word)
            {
                while(ispunct(word[0])) word.erase(word.begin());
                while(ispunct(word[word.size() - 1])) word.erase(word.end() - 1);
                if(!isalpha(word[0])) break;
                word2Line[word].insert(x.first);
                wordFreq[word]++;
            }
        }
    }
    void query(const string &word)
    {
        cout << "element " << word << " occurs " 
            << wordFreq[word] << " times" << endl;
        for(auto iter = word2Line[word].begin(); 
            iter != word2Line[word].end(); iter++)
        {
            cout << "\t" <<"(line " << *iter << ")" << lines[*iter] << endl;
        }
    }
private:
    shared_ptr<vector<string>> file; //输入文件
    map<string, set<int> > word2Line;
    
    unordered_map<int, string> lines;
    unordered_map<string, int> wordFreq;
};



int main()
{
    TextQuery tq;
    tq.readFile("china_daily.txt");
    tq.query("the");
    return 0;
}
