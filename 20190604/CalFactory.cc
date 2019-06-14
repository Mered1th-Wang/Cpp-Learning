#include <iostream>

using namespace std;

class Operation
{
public:
    virtual double GetResult() = 0;
    double GetNumA() { return _numA; }
    double GetNumB() { return _numB; }
    void SetNum(double a, double b)
    {
        _numA = a;
        _numB = b;
    }
    virtual ~Operation() = default;
private:
    double _numA = 0;
    double _numB = 0;
};

class OperationAdd : public Operation
{
public:
    virtual double GetResult()
    {
        double res = 0;
        res = GetNumA() + GetNumB();
        return res;
    }
};

class OperationSub : public Operation
{
public:
    virtual double GetResult()
    {
        double res = 0;
        res = GetNumA() - GetNumB();
        return res;
    }
};

class OperationMul : public Operation
{
public:
    virtual double GetResult()
    {
        double res = 0;
        res = GetNumA() * GetNumB();
        return res;
    }
};

class OperationDiv : public Operation
{
public:
    virtual double GetResult()
    {
        double res = 0;
        res = GetNumA() / GetNumB();
        return res;
    }
};

class CalculatorFactory
{
public:
    static Operation* Create(char c)
    {
        Operation *oper;
        switch(c)
        {
        case '+':
            oper = new OperationAdd();
            break;
        case '-':
            oper = new OperationSub();
            break;
        case '*':
            oper = new OperationMul();
            break;
        case '/':
            oper = new OperationDiv();
            break;
        default:
            oper = new OperationAdd();
            break;
        }
        return oper;
    }
};

int main()
{
    int a, b;
    cin >> a >> b;
    Operation * op = CalculatorFactory::Create('+');
    op->SetNum(a, b);
    double result = op->GetResult();
    cout << "result = " << result << endl;
}
