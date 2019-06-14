#include<iostream>
#include<algorithm>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<list>
#include<memory>
#include<iterator>
#include<ctime>
using namespace std;

class Observer;
class Subject{

public:
    virtual void attach(Observer *)=0;
    virtual void detach(Observer *)=0;
    virtual void notify()=0;

    virtual ~Subject(){}
};

class Observer{

public:
    virtual void update()=0;
    virtual ~Observer(){}

};

class Ring
:public Subject
{
private:
    list<Observer*> oblist;

public:
    void attach(Observer *ob)
    {
        auto it=find(oblist.begin(),oblist.end(),ob);
        if(it==oblist.end())
        {
            oblist.push_back(ob);
        }
    }

    void detach(Observer *ob)
    {

        auto  it=find(oblist.begin(),oblist.end(),ob);
        if(it!=oblist.end())
        {
            oblist.erase(it);
        }
    }
    void notify()
    {	
        int count = 0;
        for(auto & ob:oblist)//？？？？？？？？？？？？？？？？？
        {
           // printf("cout = %d\n", count++);
            ob->update();
           // printf("cout = %d\n", count++);
        }
    }
    void alarm()
    {
        //printf("alarm\n");
        notify();
    }
};

class Baby:public Observer
{
private:
    string _name;
public:
    Baby(const string &name):_name(name){}

    void update()
    {
        ::srand(::clock());
        int random=::rand()%100;
        if(random<70)
        {
            cout<<_name<<" "<<"baby crying!"<<endl;
        }
        else
        {	
            cout<<_name<<" "<<"baby sleep well like little pig!"<<endl;
        }
    }

};

class Nurse:public Observer
{
private:
    string _name;
public:
    Nurse(const string &name):_name(name){}
    //~Nurse(){}
    void update()
    {
        ::srand(::clock());
        int random=::rand()%100;
        if(random<30)
        {
            cout<<_name<<" "<<"Nurse wakes up!"<<endl;
        }
        else{

            cout<<_name << "Nurse sleep well!"<<endl;
        }	

    }


};

class Guest{
private:
    string _name;
public:
    Guest(const string &name):_name(name){}
    //~Guest(){}
    void knock(Ring & ring)
    {
        cout<<_name<<" "<<"Guest knock the door!"<<endl;
        ring.alarm();
    }

};

int main(void){

    Ring ring;
    unique_ptr<Observer> baby1(new Baby("大头儿子"));
    unique_ptr<Observer> baby2(new Baby("小头儿子"));
    unique_ptr<Observer> nurse1(new Nurse("静香一号"));
    unique_ptr<Observer> nurse2(new Nurse("静香二号"));

    ring.attach(baby1.get());
    ring.attach(baby2.get());
    ring.attach(nurse1.get());
    ring.attach(nurse2.get());

    Guest guest("大雄");
    guest.knock(ring);
}
