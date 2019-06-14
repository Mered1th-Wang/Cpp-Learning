#include <iostream>

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
    Point *pt = new Point(3, 4);
    pt->print();
    (*pt).print();
    delete pt;
    cout << endl;

    RAII<Point> p(new Point(1, 2));
    p->print();
    (*p).print();


    cout << endl;
    p.reset(new Point(5, 6));
    p->print();
    (*p).print();

    return 0;
}
