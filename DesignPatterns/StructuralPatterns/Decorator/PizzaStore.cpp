/*
Pizza acts as our abstract component class.
There are four concrete components namely PeppyPaneer , FarmHouse, Margherita, ChickenFiesta.
ToppingsDecoratoris our abstract decorator and FreshTomato , Paneer, Jalapeno, Barbeque are concrete decorators.
*/

#include<bits/stdc++.h>
using namespace std;

class Pizza {
public:
    virtual string getDesc() = 0;
    virtual int getCost() = 0;
};

class PeppyPaneer : public Pizza {
public:
    string getDesc() { return "PeppyPaneer"; }
    int getCost() { return 100; }
};

class FarmHouse : public Pizza {
public:
    string getDesc() { return "FarmHouse"; }
    int getCost() { return 150; }
};

class Mexican : public Pizza {
public:
    string getDesc() { return "Mexican"; }
    int getCost() { return 200; }
};

class Italian : public Pizza {
public:
    string getDesc() { return "Italian"; }
    int getCost() { return 250; }
};

class Tomatoes : public Pizza {
    Pizza *p;
public:
    Tomatoes(Pizza *p): p(p) {}
    string getDesc() { return p->getDesc() + " with Tomatoes"; }
    int getCost() { return p->getCost()+20; }
};

class CheezBurst : public Pizza {
    Pizza *p;
public:
    CheezBurst(Pizza *p): p(p) {}
    string getDesc() { return p->getDesc() + " with CheezBurst"; }
    int getCost() { return p->getCost()+50; }
};

int main()
{
    Pizza *pp = new Tomatoes(new PeppyPaneer());
    cout << pp->getDesc() << " " << pp->getCost() << endl;
    Pizza *mtc = new CheezBurst(new Tomatoes(new Tomatoes(new Mexican())));
    cout << mtc->getDesc() << " " << mtc->getCost() << endl;
    return 0;
}
