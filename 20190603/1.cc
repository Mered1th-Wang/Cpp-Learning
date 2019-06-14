#include <iostream>
#include <string>

using namespace std;

void func()
{
    int a;
    int b;
    int c;
    int d;
    int e;
    printf("&a = %p\n", &a);
    printf("&d = %p\n", &d);
    printf("&e = %p\n", &e);
}

int main()
{
    func();
    int x;
    printf("&x = %p\n", &x);

#if 0
    string x("abc");
    printf("x = %p\n", &x);
    
    string y = "abc";
    printf("y = %p\n", &y);

    int *pMain = (int *)&main;
    printf("pMain = %p\n", pMain);

    int *a = new int(5);
    printf("堆 = %p\n", &a);
    
    int *p = (int *)&x;
    printf("p = %p\n", p);

    cout << &("abc") << endl;
#endif
    return 0;
}
