/*
Node: Use C++14 as make_unique is being used.
Template Method pattern:
Base class implements generic methods.
Derived classes implement specific methods.

Output:
Boiling Water
Steep Tea
Pour Beverage in a Cup
Add Sugar and Lemon

Boiling Water
Brew Coffee
Pour Beverage in a Cup
Add Sugar and Milk
*/
#include <bits/stdc++.h>
using namespace std;

class Beverage {
public:
    void BoilWater() { cout << "Boiling Water\n"; }
    virtual void Brew() = 0;
    void Pour() { cout << "Pour Beverage in a Cup\n"; }
    virtual void addCondiments() = 0;
};

class Tea : public Beverage {
public:
    void Brew() override { cout << "Steep Tea\n"; }
    void addCondiments() override { cout << "Add Sugar and Lemon\n"; }
};

class Coffee : public Beverage {
public:
    void Brew() override { cout << "Brew Coffee\n"; }
    void addCondiments() override { cout << "Add Sugar and Milk"; }
};

int main()
{
    unique_ptr<Beverage> t = make_unique<Tea>();
    unique_ptr<Beverage> c = make_unique<Coffee>();

    t->BoilWater();
    t->Brew();
    t->Pour();
    t->addCondiments();

    c->BoilWater();
    c->Brew();
    c->Pour();
    c->addCondiments();
}
