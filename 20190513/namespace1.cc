#include <iostream>

namespace wd
{
int num = 10;
void display(){
    std::cout << "display()" << std::endl;
}
void cout(){
    printf("hello, world\n");
}
}

using namespace wd;

int main()
{
    std::cout << "Hello world" << std::endl;
    display();
    cout();
    return 0;
}

