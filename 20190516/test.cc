#include <string.h>
#include <iostream>

using namespace std;

class Student
{
public:
    Student(const char * name)
    :_name(new char[strlen(name) + 1]())
    {
        strcpy(_name, name);
        cout << "Student()" << endl;
    }
public:
    char * _name;
};

int main()
{
    Student stu("Mike");
    
    cout << "size = " << sizeof(stu) << endl;
    printf("&stu = %p\n", &stu); 
    
    char *pStr= (char*)&stu;
    cout << "pStr = " << pStr << endl;
    cout << "*pStr = " << *pStr << endl;
    
    return 0;
}
