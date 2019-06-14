#include <string.h>
#include <iostream>

using namespace std;

class CowString
{
    friend ostream & operator<<(ostream & cout, const CowString & rhs);
public:
    CowString();
    CowString(const char * pStr);
    CowString(const CowString & rhs);
    CowString & operator=(const CowString & rhs);
    ~CowString();
    const char * c_str() const;
    int size() const;
    int refcount();
    //char & operator[](int idx);


    class charProxy
    {
    public:
        charProxy(CowString & str, int idx):_str(str), _idx(idx)
        {
            cout << "charProxy()" << endl;      
        }
        char & operator=(char ch)
        {
            if(_idx >= 0 && _idx < _str.size())
            {

                if(_str.refcount() > 1)
                {
                    _str.decreaseRefcount();
                    char *ptmp = new char[4 + _str.size() + 1]() + 4;
                    strcpy(ptmp, _str._pStr);
                    _str._pStr = ptmp;
                    _str.initRefcount();
                    _str._pStr[_idx] = ch;
                }
                return _str._pStr[_idx];
            }
            else
            {
                cout << "out of range" << endl;
                static char nullchar = '\0';
                return nullchar;
            }

        }

        charProxy operator[](int idx);



        operator char()
        {
            cout << "operator char()" << endl;
            return _str._pStr[_idx];
        }


    private:
        CowString & _str;
        int _idx;
    };


    charProxy operator[](int idx)
    {
        return charProxy(*this, idx);
    }
private:
    void initRefcount() { *((int*)(_pStr - 4)) = 1; }
    void increaseRefcount() { ++*((int*)(_pStr - 4)); }
    void decreaseRefcount() { --*((int*)(_pStr - 4)); }

    void release();
    char * _pStr;
};


CowString::CowString()
    :_pStr(new char[4 + 1]() + 4)
{
    cout << "CowString()" << endl;
    initRefcount();
}
CowString::CowString(const char * pStr)
    :_pStr(new char[4 + strlen(pStr) + 1]() + 4)
{
    initRefcount();
    strcpy(_pStr, pStr);
    cout << "CowString(const char *)" << endl;
}
CowString::CowString(const CowString & rhs)
    :_pStr(rhs._pStr)
{
    increaseRefcount();
    cout << "CowString(const CowString &)" << endl;
}
CowString & CowString::operator=(const CowString & rhs)
{
    cout << "CowString &operator=(const CowString &)" << endl;
    if(this != &rhs)
    {
        release();
        _pStr = rhs._pStr; //浅拷贝
        increaseRefcount();
    }
    return *this;
}
CowString::~CowString()
{
    release();
}

void CowString::release()
{
    decreaseRefcount();
    if(0 == refcount())
    {
        delete [] (_pStr - 4);
        cout << "delete data" << endl;
    }
}

const char * CowString::c_str() const 
{
    return _pStr; 
}
int CowString::size() const 
{ 
    return strlen(_pStr); 
}
int CowString::refcount() 
{ 
    return *((int*)(_pStr - 4)); 
}

#if 0
//写时复制，深拷贝
char & CowString::operator[](int idx)
{
    cout << "char & operator[](int)" << endl;
    if(idx >= 0 && idx < size())
    {

        if(refcount() > 1)
        {
            decreaseRefcount();
            char *ptmp = new char[4 + size() + 1]() + 4;
            strcpy(ptmp, _pStr);
            _pStr = ptmp;
            initRefcount();
        }
        return _pStr[idx];
    }
    else
    {
        cout << "out of range" << endl;
        static char nullchar = '\0';
        return nullchar;
    }
}
#endif

ostream & operator<<(ostream & cout, const CowString & rhs)
{
    cout << rhs._pStr;
    return cout;
}

int main(void)
{
    CowString s0;
    cout << "s0 = " << s0 << endl;

    CowString s1("hello,world");
    CowString s2(s1);

    CowString s3("shenzhen");
    s3[0] = 'S';//refcount = 1

    s3 = s2;
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    cout << "s1's refcount() = " << s1.refcount() << endl;
    cout << "s2's refcount() = " << s2.refcount() << endl;
    cout << "s3's refcount() = " << s3.refcount() << endl;

    cout << endl << ">>> 执行s1[0] = 'x' 之后:" << endl; 
    s1[0] = 'x';
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    cout << "s1's refcount() = " << s1.refcount() << endl;
    cout << "s2's refcount() = " << s2.refcount() << endl;
    cout << "s3's refcount() = " << s3.refcount() << endl;

    cout << endl << ">>> 执行 cout << s2[0] << endl 之后:" << endl; 
    cout << "s2[0] = " << s2[0] << endl;// 在这里不应该进行深拷贝
    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    printf("s1's address: %p\n", s1.c_str());
    printf("s2's address: %p\n", s2.c_str());
    printf("s3's address: %p\n", s3.c_str());
    cout << "s1's refcount() = " << s1.refcount() << endl;
    cout << "s2's refcount() = " << s2.refcount() << endl;
    cout << "s3's refcount() = " << s3.refcount() << endl;

    return 0;

}

