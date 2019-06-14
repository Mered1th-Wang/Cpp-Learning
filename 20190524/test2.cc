#include <iostream>

using namespace std;

struct NoDtor{
    NoDtor() = default;
    ~NoDtor() = delete;
};

int main()
{
    //NoDtor nd; //erorr，NoDtor的析构函数delete
    NoDtor *p = new NoDtor(); 
    //delete p; //error，NoDtor的析构函数delete
    return 0;
}
