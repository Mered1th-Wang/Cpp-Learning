#include <iostream>

using namespace std;

int main()
{
    //int iNum = 1;
    //int * pInt = &iNum;
    //float * pFloat = static_cast<float *>(pInt);  //error
    
    float a = 1.2;
    int b = static_cast<int>(a);
    cout << b << endl;
    return 0;
}

