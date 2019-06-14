#include <iostream>

using namespace std;

#ifdef _cplusplus
extern "C"
{
#endif
double add(double a, double b){
    return a + b;
}
#ifdef _cplusplus
}
#endif

int add(int a, int b){
    return a + b;
}

int add(int a, int b, int c){
    return a + b + c;
}
double add(int a, double b){
    return a + b;
}

int main()
{
    double a = 1.2, b = 2.3;
    int c = 3;
    cout << add(a, b) << endl;
    //cout << add(a, b, c) <<endl;
    cout << add(c, a) << endl;
    return 0;
}

