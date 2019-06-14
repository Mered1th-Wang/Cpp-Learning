#include <iostream>
#include <functional>

using namespace std;

int main()
{
    int y = 1;
    function<int(int)> f = [&](int x){return ++x;};
    cout << f(y) << endl;
    return 0;
}
