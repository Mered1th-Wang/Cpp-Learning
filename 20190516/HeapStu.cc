#include <string.h>
#include <stdlib.h>
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
    
    void destroy()
    {
        cout << "0" << endl;
        delete this;
        cout << "1" << endl;
    }
    
public:
    void operator delete(void * ret)
    {
        cout << "void operator delete(void *)" << endl;
        free(ret);
    }

private:
    ~Student()
    {
        delete [] _name;
        cout << "~Student" << endl;
    }

private:
    char *_name;
    int _id;
};


int main()
{
    Student * stu1 = new Student("John", 1001);
    stu1->print();
    stu1->destroy();  
    return 0;
}

