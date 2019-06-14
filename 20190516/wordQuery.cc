#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

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
            if(isdigit(word[0])) continue;
            num[word]++;
        }
    }
    void print() const
    {
        // for(auto iter = num.begin(); iter != num.end(); ++iter)
        // {
        //     cout << iter->first << " " << iter->second << endl;
        // }

        vector<pair<string, int> > num_map(num.begin(), num.end());
        sort(num_map.begin(), num_map.end(), cmp);
        for(int i = 0; i < 10; i++)
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
    string filename = "The_Holy_Bible.txt";
    Dictionary test(filename);
    test.read();
    test.print();
    return 0;
}
