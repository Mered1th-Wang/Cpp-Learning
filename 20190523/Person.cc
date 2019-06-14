#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person(string name, int age):_name(name), _age(age){}
    void display()
    {
        cout << "name = " << this->_name << endl;
        cout << "age = " << this->_age << endl;
    }
private:
    string _name;
    int _age;
};

class Employee : public Person
{
public:
    Employee(string name, int age, string department, int salary)
        :Person(name, age), _department(department), _salary(salary){}
    void display()
    {
            Person::display();
            cout << "department = " << _department << endl
            << "salary = " << _salary << endl;
    }
    int getSalary(){ return this->_salary; }
private:
    string _department;
    int _salary;
};

int main()
{
    Employee t1("zhangsan", 35, "CTO", 50000);
    Employee t2("lisi", 25, "CSO", 20000);
    Employee t3("wangwu", 50, "CEO", 100000);
    t1.display();
    cout << "-----------" << endl;
    t2.display();
    cout << "-----------" << endl;
    t3.display();
    cout << "-----------" << endl;
    
    cout << "Average = " << (t1.getSalary() + t2.getSalary() + t3.getSalary() / 3) << endl;

    
    return 0;
}
