#include <iostream>
#include <memory>
#include <string>

using namespace std;

struct FileCloser
{
    void operator()(FILE * fp)
    {
        if(fp){
            fclose(fp);
            cout << "fclose " << endl;
        }
    }
};

void test0()
{
    unique_ptr<FILE, FileCloser> up(fopen("test", "a+"));
    string msg("abc\n");
    fwrite(msg.c_str(), sizeof(char), msg.size(), up.get());
}

void test1()
{
    shared_ptr<FILE> sp(fopen("test", "a+"), FileCloser());
    string msg("this is a new line\n");
    fwrite(msg.c_str(), 1, msg.size(), sp.get());
}


int main()
{
    test1();
    return 0;
}
