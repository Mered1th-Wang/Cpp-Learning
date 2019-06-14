#include <iostream>

using namespace std;

void printStatus()
{
    cout << "badbit = " << cin.bad() << endl
        << "failbit = " << cin.fail() << endl
        << "eofbit = " << cin.eof() << endl
        << "goodbit = " << cin.good() << endl;
}

void test0()
{
    int num = -1;
    printStatus();
    while(cin >> num, !cin.eof())
    {
        cout << "num = " << num << endl;
        printStatus();
        if(!cin.good())
        {
            cin.clear();
            cin.ignore(1024, '\n');
            printStatus();
        }
    }
    cin.clear();
    cin.ignore(1024, '\n');
    cout << "input string:" << endl;
    string str;
    cin >> str;
    cout << "str = " << str << endl;
}

int main()
{
    test0();
    return 0;
}
