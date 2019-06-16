#include <iostream>

using namespace std;

union Example
{
    int num;
    char ch;
}

void test0()
{
    int num = 0x12345678;
    char * p = (char *)&num;
    printf("%x\n", *p);
    return 0;
}

void test1()
{
    union Example e;
    e.num = 1;
    if(e.ch ==  )
}
