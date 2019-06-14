#include <iostream>

using namespace std;

class SafeFile{
public:
    SafeFile(FILE * fp):_fp(fp){}

    void write(const string & msg){
        cout << "fwrite" << endl;
        fwrite(msg.c_str(), sizeof(char), msg.size(), _fp);
    }

    ~SafeFile()
    {
        if(_fp){
            fclose(_fp);
            cout << "fclose" << endl;
        }
    }


private:
         FILE * _fp;
};

int main()
{
    SafeFile sf(fopen("test", "a+"));
    sf.write("helloworld\n");

    return 0;
}
