#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> mp{{"正常收费", 0}, {"满300返100", 1}, {"打八折", 2}};

class CashSuper
{
public:
    virtual double accpetCash(double money) = 0;
};

class CashNormal : public CashSuper
{
public:
    virtual double accpetCash(double money){ return money; }
};

class CashRebate : public CashSuper
{
public:
    CashRebate(double moneyRebate):_moneyRebate(moneyRebate){}
    virtual double accpetCash(double money) { return money * _moneyRebate; }
private:
    double _moneyRebate = 0.9;
};

class CashReturn : public CashSuper
{
public:
    CashReturn(double moneyCondition, double moneyReturn)
        :_moneyCondition(moneyCondition), _moneyReturn(moneyReturn){}
    double accpetCash(double money)
    {
        double result = money;
        if(money >= _moneyCondition)
        {
            result = money - (money / _moneyCondition) * _moneyReturn; 
        }
        return result;
    }
private:
    double _moneyCondition = 0.0;
    double _moneyReturn = 0.0;
};

class CashFactory
{
public:
    static CashSuper* createCashAccept(string type)
    {
        int StringValue = mp[type];
        CashSuper * cs = nullptr;
        switch(StringValue)
        {
        case 0:
            cs = new CashNormal();
            break;
        case 1:
            cs = new CashReturn(300, 100);
            break;
        case 2:
            cs = new CashRebate(0.8);
            break;
        }
        return cs;
    }
};


int main()
{
    double total = 0.0;
    string super;
    cin >> super;
    CashSuper *p = CashFactory::createCashAccept(super);
    total = p->accpetCash(300);
    cout << "total = " << total << endl;
    return 0;
}
