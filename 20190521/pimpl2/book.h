#ifndef __PUBLIC_H__
#define __PUBLIC_H__

#include <iostream>
#include <string>

class Book
{
public:
    Book();
    ~Book(); 

    void print();

private:
    class Booklmpl;
    Booklmpl* pimpl;
};

#endif
