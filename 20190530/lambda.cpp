#include <iostream>
#include <vector>

using namespace std;

vector<int> t1{1, 3};

void test()
{
    vector<int> t2{2, 3};
    return;
}

int main()
{
    vector<int> numbers{1, 2, 3, 4, 5};
    vector<int> num{3, 4, 5};
    auto f1 = [=](){
        cout << "lambda expression" << endl;
        cout << "numbers[0] = " << numbers[0] << endl;
        cout << "num[0] = " << num[0] << endl; 
        cout << "t1[0] = " << t1[0] << endl; 
        //cout << "t2[0] = " << t2[0] << endl;  //只能捕获同一函数栈内的变量
    };
    f1();
    cout << endl;
    
    auto f2 = [&](){
        num[1] = 100;
    };
    f2();
    for(auto &i: num)
    {
        cout << i << " ";
    }
    cout << endl;
    
    auto f3 = [&num](){
        return num[1];
    };
    cout <<"num[1] = " << f3() << endl;

    auto f4 = [=]() mutable{
        num[1] = 3;
        cout <<"after change, num[1] = " << num[1] << endl;
    };

    size_t v1 = 42;
    auto f5 = [v1]() mutable { return ++v1; };
    cout << "v1 = " << v1 << endl;
    cout << "v1' = " << f5() << endl;
    return 0;
}
