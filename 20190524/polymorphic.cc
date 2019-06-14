#include <string>
#include <iostream>

using namespace std;


#if 0
class Calculator
{
public:
    void set1(int val)
    {
        val1 = val;
    }
    void set2(int val)
    {
        val2 = val;
    }
    int getResult(string oper)
    {
        if(oper == "+") return val1 + val2;
        else if(oper == "-") return val1 - val2;
    }
private:
    int val1;
    int val2;
};
#endif

//面向对象设计原则之开闭原则 : 对修改关闭，对扩展开放
//利用多态实现计算器
class abstractCalculator
{
public:
    //virtual int getResult() { return 0; }
    void set1(int val) {  val1 = val; }
    void set2(int val) { val2 = val; }
    int get1() { return this->val1; }
    int get2() { return this->val2; }

    //如果父类中有纯虚函数，子类继承父类后必须实现纯虚函数
    virtual int getResult() = 0;
private:
    int val1;
    int val2;
};

class PlusCalculator : public abstractCalculator
{
public:
    virtual int getResult() { return get1() + get2(); }
};

class SubCalculator : public abstractCalculator
{
public:
    virtual int getResult() { return get1() - get2(); }
};

class MultiCalculator : public abstractCalculator
{
public:
    virtual int getResult() { return get1() * get2(); }
};

class DivCalculator : public abstractCalculator
{
public:
    virtual int getResult() { return get1() / get2(); }
};

void test02()
{
    abstractCalculator * abc;
    abc = new PlusCalculator;

    abc->set1(10);
    abc->set2(5);
    cout << abc->getResult() << endl;
}

void test03()
{
    abstractCalculator * abc;
    abc = new SubCalculator;

    abc->set1(10);
    abc->set2(5);
    cout << abc->getResult() << endl;
}

void test04()
{
    abstractCalculator * abc;
    abc = new MultiCalculator;

    abc->set1(10);
    abc->set2(5);
    cout << abc->getResult() << endl;
}

void test05()
{
    abstractCalculator * abc;
    abc = new DivCalculator;

    abc->set1(10);
    abc->set2(5);
    cout << abc->getResult() << endl;
}

int main()
{
    test04();
    test05();
    return 0;
}
