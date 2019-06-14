#include <string>
#include <iostream>
using namespace std;

class LeiFeng
{
public:
    virtual void Sweep()
    {
        cout << "LeiFeng sweep" << endl;
    }
};

//学雷锋的学生，对应于ConcreteProduct
class Student : public LeiFeng
{
public:
    virtual void Sweep()
    {
        cout << "Student sweep" << endl;
    }
};

//学雷锋的志愿者，对应于ConcreteProduct
class Volunteer : public LeiFeng
{
public:
    virtual void Sweep()
    {
        cout << "Volunteer sweep" << endl;
    }
};

//工厂抽象基类 Creator
class LeiFengFactory
{
public:
    virtual LeiFeng * CreateLeiFeng()
    {
        return new LeiFeng();
    }
};

//工厂具体类
class StudentFactory : public LeiFengFactory
{
public:
    virtual LeiFeng * CreateLeiFeng()
    {
        return new Student();
    }
};

//工厂具体类
class VolunteerFactory : public LeiFengFactory
{
public:
    virtual LeiFeng* CreateLeiFeng()
    {
        return new Volunteer();
    }
};

int main()
{
    LeiFengFactory * factory = new LeiFengFactory();
    LeiFeng * student = new Student();
    LeiFeng * volunteer = new Volunteer();
    student->Sweep();
    volunteer->Sweep();
    delete factory;
    delete student;
    delete volunteer;
    return 0;
}
