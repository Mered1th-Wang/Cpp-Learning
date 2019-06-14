#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

vector<string> file;

void test0()
{
    ifstream ifs;
    ifs.open("io1.cc");
    if(!ifs.good())
    {
        perror("open");
        return;
    }
    string word;
    while(ifs >> word)
    {
        cout << word << endl;
        file.push_back(word);
    }
    ifs.close();
}

void test1()
{
    ifstream ifs;
    ifs.open("io1.cc");
    if(!ifs.good())
    {
        perror("open");
        return;
    }
    string line;
    while(getline(ifs, line))
    {
        cout << line << endl;
        file.push_back(line);
    }
    ifs.close();
}

void test2()
{
    ofstream ofs("test", ios::app);
    if(!ofs)
    {
        perror("ofs");
        return;
    }
    cout << "pos = " << ofs.tellp() << endl;
    ofs << "that's new line! " << endl;
}

void test3()
{
    fstream fs("test", ios::app);
    if(!fs)
    {
        perror("fs");
        return;
    }
    cout << "pos : " << fs.tellg() << endl;
    int num;
    cout << "plz input 5 numbers:" << endl;
    for(int idx = 0; idx != 5; ++idx)
    {
        cin >> num;
        fs << num << " ";
    }
    fs << endl;
    fs.seekg(0);//两个偏移指针是不同的！
    fs.seekp(0);
    for(int idx = 0; idx != 5; ++idx)
    {
        fs >> num;
        cout << num << " ";
    }
    cout << endl;
    fs.close();
}

void test4()
{
    ifstream ifs("test", ios::ate);
    perror("ifs");
    int length = ifs.tellg();
    char * buf = new char[length + 1];
    ifs.seekg(0);
    ifs.read(buf, length);
    string content(buf);
    cout << content << endl;

    delete [] buf;
    ifs.close();
}

int main()
{
    //test0();
    //test1();
    //test2();
    //test3();
    test4();
    return 0;
}
