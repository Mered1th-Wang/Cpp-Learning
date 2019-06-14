#include <cstring>
#include <iostream>

const int N = 3;

using namespace std;

class Queue
{
public:
    Queue():size(0), pfront(0), pback(0)
    {
        memset(arry, 0, sizeof(arry));
        cout << "Create Queue OK!" << endl;
    }
    void push(int);
    void pop();
    int front();
    int back();
    bool empty();
    bool full();
private:
    int arry[N];
    int size;
    int pfront, pback;
};

void Queue::push(int x)
{
    if(full())
    {
        cout << "Push failed! Queue is full!" << endl;
    }
    else{
        arry[size++] = x;
        pback = size - 1;
    }
}
void Queue::pop()
{
    if(empty())
    {
        cout << "Pop failed! Queue is empty!" << endl;
    }
    else{
        pfront++;
    }
}
int Queue::front()
{
    if(empty())
    {
        cout << "Get front failed! Queue is empty!" << endl;
        return -1;
    }
    else return arry[pfront];
}
int Queue::back()
{
    if(empty())
    {
        cout << "Get back failed! Queue is empty!" << endl;
        return -1;
    }
    else return arry[pback];
}
bool Queue::empty()
{   
    if(size == 0)
    {
        cout << "Queue is empty!" << endl;
        return true;
    }
    else return false;
}
bool Queue::full()
{
    if(size == N)
    {
        cout << "Queue is full!" << endl;
        return true;
    }
    else return false;
}

int main()
{
    Queue q;
    q.empty();
    q.push(5);
    cout << "after push 5" << endl;
    cout << "q.front = " << q.front() << endl;
    cout << "q.back = " << q.back() << endl;
    
    cout << endl;
    q.push(3);
    cout << "after push 3" << endl;
    cout << "q.front = " << q.front() << endl;
    cout << "q.back = " << q.back() << endl;
    
    cout << endl;
    q.push(7);
    cout << "after push 7" << endl;
    cout << "q.front = " << q.front() << endl;
    cout << "q.back = " << q.back() << endl;
    q.full();
    
    cout << endl;
    q.pop();
    cout << "after pop()" << endl;
    cout << "q.front = " << q.front() << endl;
    cout << "q.back = " << q.back() << endl;
    return 0;
}
