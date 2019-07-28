/*
Stratergy Design Pattern
Example referred from Head First Design Patterns

Output:
 Mallard Duck  Swimming  Flying with wings  Quack 
 RedHead Duck  Swimming  Flying with wings  Quack 
 Rubber Duck  Swimming  Fly No Way  Squeak 
 Decoy Duck  Swimming  Flying with Rocket Power  Mute Quack 
*/
#include <iostream>
#include <memory>
using namespace std;

class FlyBehaviour {
public:
    virtual void fly() = 0;
};

class QuackBehaviour {
public:
    virtual void quack() = 0;
};

class FlyWithWings : public FlyBehaviour {
    void fly() override {
        cout << " Flying with wings ";
    }
};

class FlyNoWay : public FlyBehaviour {
    void fly() override {
        cout << " Fly No Way ";
    }
};

class FlyRocketPowered : public FlyBehaviour {
    void fly() override {
        cout << " Flying with Rocket Power ";
    }
};

class Quack : public QuackBehaviour {
    void quack() override {
        cout << " Quack ";
    }
};

class Squeak : public QuackBehaviour {
    void quack() override {
        cout << " Squeak ";
    }
};

class MuteQuack : public QuackBehaviour {
    void quack() override {
        cout << " Mute Quack ";
    }
};

class Duck {
public:
    Duck(FlyBehaviour *fb, QuackBehaviour *qb) : fb_(fb), qb_(qb) {}
    void swim() {
        cout << " Swimming ";
    }
    virtual void display() = 0;
    void fly() { fb_->fly(); }
    void quack() { qb_->quack(); }
private:
    unique_ptr<FlyBehaviour>   fb_;
    unique_ptr<QuackBehaviour> qb_;
};

class MallardDuck : public Duck {
public:
    MallardDuck(FlyBehaviour *fb, QuackBehaviour *qb) : Duck(fb, qb) {}
    void display() override {
        cout << " Mallard Duck ";
    }
};

class RedHead : public Duck {
public:
    RedHead(FlyBehaviour *fb, QuackBehaviour *qb) : Duck(fb, qb) {}
    void display() override {
        cout << " RedHead Duck ";
    }
};

class Rubber : public Duck {
public:
    Rubber(FlyBehaviour *fb, QuackBehaviour *qb) : Duck(fb, qb) {}
    void display() override {
        cout << " Rubber Duck ";
    }
};

class Decoy : public Duck {
public:
    Decoy(FlyBehaviour *fb, QuackBehaviour *qb) : Duck(fb, qb) {}
    void display() override {
        cout << " Decoy Duck ";
    }
};

int main() {
    unique_ptr<Duck> d = make_unique<MallardDuck>(new FlyWithWings(), new Quack());
    d->display();
    d->swim();
    d->fly();
    d->quack();
    cout << endl;
    
    d = make_unique<RedHead>(new FlyWithWings(), new Quack());
    d->display();
    d->swim();
    d->fly();
    d->quack();
    cout << endl;
    
    d = make_unique<Rubber>(new FlyNoWay(), new Squeak());
    d->display();
    d->swim();
    d->fly();
    d->quack();
    cout << endl;
    
    d = make_unique<Decoy>(new FlyRocketPowered(), new MuteQuack());
    d->display();
    d->swim();
    d->fly();
    d->quack();
    cout << endl;
    
    return 0;
}
