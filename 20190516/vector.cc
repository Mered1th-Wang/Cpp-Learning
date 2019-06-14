#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> a(5);
    //a.reserve(5);
    //a.resize(5);
    for(auto &i: a){
        cout << i << " ";
    }
    cout << endl;
    cout << "---------" << endl;
    cout << a.size() << endl;
    cout << a.capacity() << endl;
    return 0;
}
