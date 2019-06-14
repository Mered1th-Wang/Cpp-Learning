#include <cstring>
#include <iostream>

const int N = 3;

using namespace std;

class Stack
{
public:
    Stack():size(0)
    {
        memset(arry, 0, sizeof(arry));
        cout << "Create Stack OK!" << endl;
    }
    void push(int);
    void pop();
    int top();
    bool empty();
    bool full();
private:
    int arry[N];
    int size;
};

bool Stack::empty()
{
    if(0 == this->size)
    {
        cout << "Stack is empty!" << endl;
        return true;
    }
    else return false;
}

bool Stack::full()
{
    if(N == this->size)
    {
        cout << "Stack is full!" << endl;
        return true;
    }
    else return false;
}

void Stack::push(int x)
{
    if(full()) 
    {
        cout << "Push failed! Stack is full!" << endl;
    }
    else{
        arry[size++] = x;
    }
}

void Stack::pop()
{
    if(empty())
    {
        cout << "Pop failed! Stack is empty!" << endl;
    }
    else{
        --size;
    }
}

int Stack::top()
{
    if(empty()){
        cout << "Get top element failed! Stack is empty!" << endl;
        return -1;
    }
    else{
        return arry[size - 1];
    }
}

int main()
{
    Stack st;
    st.empty();
    st.push(10);
    st.push(12);
    st.push(14);
    cout << "top()" << st.top() << endl;
    st.full();
    st.pop();
    cout << "top()" << st.top() << endl;
    
    return 0;
}

