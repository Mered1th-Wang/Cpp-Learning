#include <cstdlib>
#include <iostream>
#include <list>
#include <memory>
#include <algorithm>

using namespace std;

class Observer;

class Subject
{
public:
    virtual void attach(Observer *)=0;
    virtual void detach(Observer *)=0;
    virtual void notify()=0;

    virtual ~Subject() {}

};

class Observer
{
public:
    //virtual void update(Subject * )=0;// 拉模式 => 观察者主动获取
    //virtual void update(const string & msg) =0;//推模式=> 观察者被动获取
    virtual void update() = 0;

    virtual string name() const = 0;

    virtual ~Observer() {}

protected:
    //Subject * _subject;
};

class Ring
: public Subject
{
public:
    void attach(Observer *ob) 
    {
        auto it = find(_oblist.begin(), _oblist.end(), ob);
        if(it == _oblist.end())
            _oblist.push_back(ob);
    }

    void detach(Observer * ob)
    {
        auto it = find(_oblist.begin(), _oblist.end(), ob);
        if(it != _oblist.end())
            _oblist.erase(it);
    }

    void alarm()
    {
        notify();
    }

    void notify() 
    {
        for(auto & ob : _oblist) {
            ob->update();
        }
    }
private:
    list<Observer*> _oblist;
    list<Observer*> _goldenlist;//针对于不同类型的用户，做个性化的通知
    list<Observer*> _diamondlist;
};


class Baby
: public Observer
{
public:
    Baby(const string name)
        : _name(name)
    {}

    string name() const {   return _name;   }

    void update() {
        ::srand(::clock());
        int random = ::rand() % 100;
        if(random < 70) {
            cout << ">> Baby "<< _name << " started crying!" << endl;

        } else {
            cout << ">> Baby " << _name << " sleeps sweetly!" << endl;

        }

    }

private:
    string _name;

};

class Nurse
: public Observer
{
public:
    Nurse(const string & name)
        : _name(name)
    {}

    string name() const {   return _name;   }   

    void update() 
    {
        ::srand(::clock());
        int random = ::rand() % 100;
        if(random < 70) {
            cout << ">> Nurse " << _name << " is ready to open the door!" << endl;

        } else {
            cout << ">> Nurse " << _name << " sleeps sweetly!" << endl;

        }

    }
private:
    string _name;

};

class Guest
{
public:
    Guest(const string & name)
        : _name(name)
    {}

    void knock(Ring & ring)
    {
        cout << "Guest " << _name << " knock at the door！" << endl;
        ring.alarm();

    }

private:
    string _name;

};


int main(void)
{
    Ring ring;
    unique_ptr<Observer> baby1(new Baby("baby1"));
    unique_ptr<Observer> baby2(new Baby("baby2"));
    unique_ptr<Observer> nurse1(new Nurse("Nurse1"));
    unique_ptr<Observer> nurse2(new Nurse("Nurse2"));

    ring.attach(baby1.get());
    ring.attach(baby2.get());
    ring.attach(nurse1.get());
    ring.attach(nurse2.get());

    Guest guest("Doctor");
    guest.knock(ring);

    cout << ">> nurse " << nurse1->name() << " has left the room." << endl;
    ring.detach(nurse1.get());
    guest.knock(ring);

    return 0;

}

