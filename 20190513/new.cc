#include <iostream>

using namespace std;

void test(){
    int *pint = new int(10);
    cout << "*pint = " << *pint << endl;
    delete pint;

    int * parray = new int[10]();
    for(int idx = 0; idx != 10; ++idx){
        parray[idx] = idx;
    }
    for(int idx = 0; idx != 10; ++idx){
        cout << parray[idx] << " ";
    }
    cout << endl;
    delete [] parray;
}

int main()
{
    test();
    return 0;
}

