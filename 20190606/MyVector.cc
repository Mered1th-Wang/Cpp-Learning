#include <iostream>
#include <memory>

using namespace std;

template<typename T>
class Vector
{
public:
    typedef T value_type;
    typedef T * pointer;
    typedef T * iterator;
    typedef const T * const_iterator;
    
    Vector():_start(nullptr), _finish(nullptr), _end_of_storage(nullptr){}
    ~Vector() = default;
    void push_back(const T &); 
    void pop_back();

    const_iterator begin() const { return _start; }
    const_iterator end() const { return _finish; }

    size_t size() const { return _finish - _start; }
    size_t capacity() const { return _end_of_storage - _start; }

    T & operator[](size_t idx) const
    { return _start[idx]; }

private:
    void reallocate();//重新分配内存,动态扩容要用的

private:    
    static allocator<T> _alloc;
    T * _start;      //指向数组中的第一个元素
    T * _finish; //指向最后一个实际元素之后的那个元素
    T * _end_of_storage;        //指向数组本身之后的位置
};

template <typename T>
allocator<T> Vector<T>::_alloc;

template <typename T>
void Vector<T>::push_back(const T & t)
{
    if(size() == capacity()){
        reallocate();
    }
    _alloc.construct(_finish++, t);//对象的构造
}

template <typename T>
void Vector<T>::pop_back()
{
    if(size() > 0){
        _alloc.destroy(--_finish);
    }
}

template <typename T>
void Vector<T>::reallocate()
{
    size_t oldSpace = capacity();
    size_t newSpace = 2 * oldSpace > 0 ? 2 * oldSpace : 1;
    T * pTmp = _alloc.allocate(newSpace);
    if(_start){
        uninitialized_copy(_start, _finish, pTmp);//复制到一个未初始化的存储区
        while(_finish != _start){
            _alloc.destroy(--_finish);
        }
        _alloc.deallocate(_start, oldSpace);
    }

    _start = pTmp;
    _finish = _start + oldSpace;
    _end_of_storage = _start + newSpace;
}

template <typename Container>
void display(const Container & c)
{
    typename Container::const_iterator it = c.begin();
    while(it != c.end()){
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    cout << "c'size = " << c.size() << endl
        << "c'capacity = " << c.capacity() << endl;
}

int main()
{
    Vector<int> numbers;
    display(numbers);

    for(int idx = 0;idx != 10; ++idx){
        numbers.push_back(idx);
        display(numbers);
    }
    cout << "numbers[6] = " << numbers[6] << endl;
    return 0;
}
