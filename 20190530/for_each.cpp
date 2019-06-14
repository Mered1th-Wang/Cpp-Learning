#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> vi{-3, -6, 1, 2, -5, 0};

    transform(vi.begin(), vi.end(), vi.begin(),
              [](int i) { if(i < 0) return -i; else return i; });
    for(auto &i : vi)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<char> vc{'a', 'b', 'c', 'd', 'e'};
    for_each(vc.begin(), vc.end(), [](const char c){ cout << c << "    " ;});
    cout << endl;
    
    cout << "---------------------" << endl;
    for_each(vc.begin(), vc.end(), [](char c)mutable{ cout << ++c << " "; });
    cout << endl;


    transform(vc.begin(), vc.end(), vc.begin(), [](char c){ return c + 1; });
    for(auto &i : vc)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
