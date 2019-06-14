#include "book.h"

using namespace std;

class Book::Booklmpl
{
public:
    void print();
private:
    string m_Contents;
    string m_Title;
};

Book::Book()
{
    pimpl = new Booklmpl();
}

Book::~Book()
{
    delete pimpl;
}

void Book::print()
{
    pimpl->print();
}

void Book::Booklmpl::print()
{
    cout << "print from Booklmpl" << endl;
}


