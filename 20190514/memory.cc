#include <iostream>

using namespace std;

int a = 10; 

int main(){
    int b;
    char s[] = "1234";
    const char *s1 = "12345";
    static int c = 0;
    char *p1 = new char[10]();
    char *p2 = new char[5]();


    printf("&a = %p\n", &a); //全局变量——全局静态区
    printf("&b = %p\n", &b); //栈空间内

    printf("s = %p\n", &s); 
    printf("&s[0] = %p\n", &s[0]);
    printf("&s = %p\n", &s); //栈空间内
    printf("s1 = %p\n", s1); //常量区
    printf("&s1 = %p\n", &s1);//栈空间内
    printf("&p1 = %p\n", &p1);//栈空间内
    printf("&p2 = %p\n", &p2);//栈空间内
    printf("p1 = %p\n", p1); //堆空间内
    printf("&c = %p\n", &c); //静态变量——全局静态区

//    &a = 0x565aa008
//    &b = 0xfffe7ea4
//    &s = 0xfffe7eb7
//    s1 = 0x565a8911
//    &s1 = 0xfffe7ea8
//    &p1 = 0xfffe7eac
//    &p2 = 0xfffe7eb0
//    p1 = 0x56b88b70
//    &c = 0x565aa014


        return 0;
}
