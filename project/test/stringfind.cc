#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a = "abc";
    char f = 'q';
    string str = string(1, f);
    cout << str <<  endl;
    if(a.find(f) != string::npos)
    {
        printf("true\n");
    }

    return 0;
}
