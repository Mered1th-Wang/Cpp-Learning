#include <iostream>

using namespace std;

class Strategy
{
public:
    virtual void AlgorithmInterface();
};

class ConcreteStrategyA : public Strategy
{
public:
    virtual void AlgorithmInterface()
    {

    }
};

class ConcreteStrategyB : public Strategy
{
public:
    virtual void AlgorithmInterface()
    {

    }
};


class ConcreteStrategyC : public Strategy
{
public:
    virtual void AlgorithmInterface()
    {

    }
};


class Context
{
public:
    Context(Strategy strategy)
    {
        this->_strategy = strategy;
    }

    void ContextInterface()
    {
        Strategy.AlgorithmInterface();
    }
    
private:
    Strategy _strategy;
};

class CashContext
{
public:
    CashContext (CashSuper csuper)
    {
        this.cs = csuper;
    }
    double GetResult(double money)
    {
        return cs.acceptCash(money);
    }

private:
    CashSuper cs;
};

int main()
{
    Context context;
    context = new Context(new ConcreteStrategyA());
    context.ContextInterface();
    context = new Context(new ConcreteStrategyB());
    context.ContextInterface();
    context = new Context(new ConcreteStrategyC());
    context.ContextInterface();
}


