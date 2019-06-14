#include <iostream>
#include <string>
using namespace std;

int main()
{
    string test = "ab1";
    cout << test[test.size() - 1] << endl;
    
    test.erase(test.end() - 1);
    cout << test << endl;
    
    return 0;
}
