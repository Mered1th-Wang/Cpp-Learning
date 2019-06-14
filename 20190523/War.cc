#include <iostream>

using namespace std;

static int ID = 1;
static int health = 1000;

class Warrior
{
public:
    Warrior(const int m):_HP(m), _ID(ID)
    {
        ID++;
        health -= m;
    }
private:
    int _HP;
    int _ID;
};

class Dragon : public Warrior
{
public:
    Dragon(const int m):Warrior(m), _WP((ID - 1) % 3), _Morale( health / m ){}
    
private:
    int _WP;
    double _Morale;
};

class ninja : public Warrior
{
public:
    ninja(const int m):Warrior(m), _WP1((ID - 1) % 3), _WP2(ID % 3){}

private:
    int _WP1;
    int _WP2;
};

class Iceman : public Warrior
{
public:
    Iceman(const int m):Warrior(m), _WP((ID - 1) % 3){}
    
private:
    int _WP;
};

class Lion : public Warrior
{
public:
    Lion(const int m):Warrior(m), _Loyalty(health){}
    
private:
    int _Loyalty;
};

class Wolf : public Warrior
{
public:
    Wolf(const int m):Warrior(m){}
};

int main()
{
    Wolf wolf1(1);
    Wolf wolf2(1);
    Wolf wolf3(1);
    Wolf wolf4(1);
    Iceman iceman5(2);
    return 0;
}
