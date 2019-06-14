#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class RAII
{
public:
    RAII(T * data):_data(data){}

    T * operator->() { return _data; }

    T & operator*() { return *_data; };

    T * get() { return _data; }

    void reset(T * data)
    {
        if(_data) delete _data;
        _data = data;
    }

    ~RAII()
    {
        if(_data){
            delete _data;
            cout << "delete heap data!" << endl;
        }
    }

private:
    T * _data;
};


class SafeFile{
public:
    SafeFile(FILE * fp):_fp(fp){}

    void write(const string & msg){
        cout << "fwrite" << endl;
        fwrite(msg.c_str(), sizeof(char), msg.size(), _fp);
    }

    ~SafeFile()
    {
        if(_fp){
            fclose(_fp);
            cout << "fclose" << endl;
        }
    }


private:
    FILE * _fp;
};

class Point
{
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix)
          , _iy(iy)
    {   cout << "Point(int,int)" << endl;   }

    void print() const
    {
        cout << "(" << _ix
            << "," << _iy
            << ")" << endl;

    }

    ~Point() {  cout << "~Point()" << endl; }

private:
    int _ix;
    int _iy;

};

int main()
{
    Point * pt = new Point(1, 2);
    auto_ptr<Point> ap(pt);
    ap->print();
    (*ap).print();

    auto_ptr<Point> ap2(ap);
    ap2->print();
    (*ap2).print();


    //auto_ptr<Point> ap3 = pt; //error
    //ap3->print();
    //(*ap3).print();

    return 0;
}
