#include <iostream>

using namespace std;

class Operation
{
public:
    virtual double GetResult()
    {
        double dResult = 0;
        return dResult;
    }
public:
    int m_nFirst;
    int m_nSecond;
};

class AddOperation : public Operation
{
public:
    AddOperation(int a, int b)
    {
        m_nFirst = a;
        m_nSecond = b;
    }
    virtual double GetResult()
    {
        return m_nFirst + m_nSecond;
    }
};

class SubOperation : public Operation
{
public:
    SubOperation(int a, int b)
    {
        m_nFirst = a;
        m_nSecond = b;
    }
    virtual double GetResult()
    {
        return m_nFirst - m_nSecond;
    }
};

class Context
{
public:
    Context(char cType)
    {
        switch(cType)
        {
        case '+':
            op = new AddOperation(3, 8);
            break;
        case '-':
            op = new SubOperation(5, 2);
            break;
        }
    }
    double GetResult()
    {
        return op->GetResult();
    }
private:
    Operation * op;
};

int main()
{
    Context * test = new Context('+');
    cout << test->GetResult() << endl;
    return 0;
}
