#include <string.h>
#include <iostream>

using namespace std;

class Student{
public:
    Student(const char* name, int id):_name(new char[strlen(name) + 1]()), _id(id)
    {
        strcpy(_name, name);
        cout << "Student(string, int)" << endl;
    }
    void print() const
    {
        cout << "Name:" << _name << ", Id:" << _id << endl;
    }
    
    ~Student()
    {
        delete [] _name;
        cout << "~Student" << endl;
    }

private:

    void * operator new(size_t sz);
    void operator delete(void* ret);

private:
    char *_name;
    int _id;
};


int main()
{
    Student stu1("Mike", 1000);
    //Student * stu2 = new Student("John", 1001);
    stu1.print();
    return 0;
}

