#include <iostream>
#include <memory>
#include <vector>
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

shared_ptr<Point> getPoint()
{
    shared_ptr<Point> point(new Point(3, 4));
    return point;
}


int main()
{
    Point * pt = new Point(1, 2);
    shared_ptr<Point> ap(pt);
    ap->print();
    (*ap).print();


    shared_ptr<Point> ap2(ap);//将引用计数加1

    {
    shared_ptr<Point> ap3 = ap; //左值
    
    cout << "ap3's get = " << ap3.get() << endl;
    cout << "ap3's use_count = " << ap3.use_count() << endl;
    cout << "ap2's get = " << ap2.get() << endl;
    cout << "ap2's use_count = " << ap2.use_count() << endl;
    
    }
    cout << "退出语句块" << endl;
    cout << "ap2's get = " << ap2.get() << endl;
    cout << "ap2's use_count = " << ap2.use_count() << endl;




#if 0
    //shared具有移动语义
    shared_ptr<Point> up = getPoint();
    vector<shared_ptr<Point>> points;
    points.push_back(shared_ptr<Point>(new Point(3, 4)));
    points.push_back(shared_ptr<Point>(new Point(3, 4)));
    points.push_back(shared_ptr<Point>(new Point(3, 4)));

    points.push_back(std::move(ap));
    points.push_back(std::move(up));
#endif
    return 0;
}
