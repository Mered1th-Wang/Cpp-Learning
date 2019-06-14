#include <iostream>

using namespace std;

class Sales_data{
public:
    Sales_data() = default;
    Sales_data(const Sales_data&) = default;
    Sales_data& operator = (const Sales_data &);
    ~Sales_data() = default;

};

Sales_data& Sales_data::operator=(const Sales_data&) = default;

struct NoCopy{
    NoCopy() = default; //使用合成的默认构造函数
    NoCopy(const NoCopy&) = delete; //阻止拷贝
    NoCopy &operator=(const NoCopy&) = delete; //阻止赋值
    ~NoCopy() = default;
};


int main()
{
    return 0;
}
