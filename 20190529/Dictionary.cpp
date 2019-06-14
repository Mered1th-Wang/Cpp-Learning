#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

//按词频排序
bool cmp(const pair<string, int> &lhs, const pair<string, int> &rhs)
{
    return lhs.second > rhs.second;
}

class Dictionary
{
public:
    Dictionary(const string &filename):_filename(filename){}
    void read()
    {
        ifstream ifs(_filename);
        string word;
        while(ifs >> word)
        {

            while(ispunct(word[0]))
            {
                word.erase(word.begin());
            }
            while(ispunct(word[word.size() - 1]))
            {
                word.erase(word.end() - 1);
            }
            if(!isalpha(word[0]))
            {
                continue;
            }
            num[word]++;
        }
    }
    void print() const
    {
        vector<pair<string, int> > num_map(num.begin(), num.end());
        sort(num_map.begin(), num_map.end(), cmp);
        for(unsigned long i = 0; i < num_map.size(); i++)
        {
            cout << num_map[i].first << "   " << num_map[i].second << endl;
        }
    }
private:
    string _filename;
    map<string, int> num;
};

int main()
{
    string filename = "china_daily.txt";
    Dictionary test(filename);
    test.read();
    test.print();
    return 0;
}
