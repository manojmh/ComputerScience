/*
Source: Head First Design Patterns
Output:
NoQuarter47
HasQuarter68
Sold90
SoldOut116
 Inserted Quarter.... 
 Turned Crank. Dispensing your GumBall.... 
 Please collect your gumball :) 
 Inserted Quarter.... 
 Turned Crank. Dispensing your GumBall.... 
 Please collect your gumball :) 
 Inserted Quarter.... 
 Turned Crank. Dispensing your GumBall.... 
 Please collect your gumball :) 
 Oops, out of gumballs! 
 Oops, out of gumballs! 
 Oops, out of gumballs! 
 Inserted Quarter.... 
 Turned Crank. Dispensing your GumBall.... 
 Please collect your gumball :) 
*/

#include <iostream>
#include <memory>
using namespace std;

class GumBallStates {
public:
    virtual void insertQuarter() = 0;
    virtual void ejectQuarter() = 0;
    virtual void turnCrank() = 0;
    virtual void dispense() = 0;
};

class NoQuarter;
class HasQuarter;
class Sold;
class SoldOut;

class GumBallMachine {
public:
    GumBallMachine(int count);
    ~GumBallMachine();

    void refill(int count);

    void insertQuarter();
    void ejectQuarter();
    void turnCrank();
    
    void setState(GumBallStates *gbs);
    GumBallStates *getNoQuarterState();
    GumBallStates *getHasQuarterState();
    GumBallStates *getSoldState();
    GumBallStates *getSoldOutState();
    void releaseBall();
    int getCount();
private:
    int count_;
    NoQuarter     *nq;
    HasQuarter    *hq;
    Sold          *s;
    SoldOut       *so;
    GumBallStates *gbs_;
};

class NoQuarter : public GumBallStates {
public:
    NoQuarter(GumBallMachine *gbm) : gbm_(gbm) { cout << __FUNCTION__ <<  __LINE__ << endl; }
    ~NoQuarter() { cout << __FUNCTION__ <<  __LINE__ << endl; }
    void insertQuarter() override {
        cout << " Inserted Quarter.... " << endl;
        gbm_->setState(gbm_->getHasQuarterState());
    }
    void ejectQuarter() override {
        cout << " No Quarter Inserted " << endl;
    }
    void turnCrank() override {
        cout << " Insert quarter " << endl;
    }
    void dispense() override {
        cout << " No Quarter Inserted " << endl;
    }
private:
    GumBallMachine *gbm_;
};

class HasQuarter : public GumBallStates {
public:
    HasQuarter(GumBallMachine *gbm) : gbm_(gbm) { cout << __FUNCTION__ <<  __LINE__ << endl; }
    ~HasQuarter() { cout << __FUNCTION__ <<  __LINE__ << endl; }
    void insertQuarter() override {
        cout << " Already Inserted a Quarter " << endl;
    }
    void ejectQuarter() override {
        cout << "Ejecting Quarted..." << endl;
        gbm_->setState(gbm_->getNoQuarterState());
    }
    void turnCrank() override {
        cout << " Turned Crank. Dispensing your GumBall.... " << endl;
        gbm_->setState(gbm_->getSoldState());
    }
    void dispense() override {
        cout << "Please Turn The Crank To Dispense " << endl;
    }
private:
    GumBallMachine *gbm_;
};

class Sold : public GumBallStates {
public:
    Sold(GumBallMachine *gbm) : gbm_(gbm) { cout << __FUNCTION__ <<  __LINE__ << endl; }
    ~Sold() { cout << __FUNCTION__ <<  __LINE__ << endl; }
    void insertQuarter() override {
        cout << " Please wait, we are already giving you a gum ball " << endl;
    }
    void ejectQuarter() override {
        cout << " Sorry, you already turned the crank " << endl;
    }
    void turnCrank() override {
        cout << " Turning twice doesn't get you another gumball! " << endl;
    }
    void dispense() override {
        gbm_->releaseBall();
        if(gbm_->getCount() > 0)
            gbm_->setState(gbm_->getNoQuarterState());
        else {
            cout << " Oops, out of gumballs! " << endl;
            gbm_->setState(gbm_->getSoldOutState());
        }
    }
private:
    GumBallMachine *gbm_;
};

class SoldOut : public GumBallStates {
public:
    SoldOut(GumBallMachine *gbm) : gbm_(gbm) { cout << __FUNCTION__ <<  __LINE__ << endl; }
    ~SoldOut() { cout << __FUNCTION__ <<  __LINE__ << endl; }
    void insertQuarter() override {
        cout << " Oops, out of gumballs! " << endl;
    }
    void ejectQuarter() override {
        cout << " Oops, out of gumballs! " << endl;
    }
    void turnCrank() override {
        cout << " Oops, out of gumballs! " << endl;
    }
    void dispense() override {
        //cout << " Oops, out of gumballs! " << endl;
    }
private:
    GumBallMachine *gbm_;
};

GumBallMachine::GumBallMachine(int count): count_(count) {
    nq = new NoQuarter(this);
    hq = new HasQuarter(this);
    s  = new Sold(this);
    so = new SoldOut(this);
    gbs_ = nq;
}

void GumBallMachine::refill(int count) {
    count_ = count;
    gbs_ = nq;
}

GumBallMachine::~GumBallMachine() {}
void GumBallMachine::setState(GumBallStates *gbs) { gbs_ = gbs; }
GumBallStates* GumBallMachine::getNoQuarterState() { return nq; }
GumBallStates* GumBallMachine::getHasQuarterState() { return hq; }
GumBallStates* GumBallMachine::getSoldState() { return s; }
GumBallStates* GumBallMachine::getSoldOutState() { return so; }
void GumBallMachine::releaseBall() { count_--; cout << " Please collect your gumball :) " << endl; }
int GumBallMachine::getCount() { return count_; }
void GumBallMachine::insertQuarter() { gbs_->insertQuarter(); }
void GumBallMachine::ejectQuarter() { gbs_->ejectQuarter(); }
void GumBallMachine::turnCrank() { gbs_->turnCrank(); gbs_->dispense(); }
//void GumBallMachine::dispense() { gbs_->dispense(); }

int main() {
    GumBallMachine gbm(3);
    gbm.insertQuarter();
    gbm.turnCrank();
    
    gbm.insertQuarter();
    gbm.turnCrank();
    
    gbm.insertQuarter();
    gbm.turnCrank();
    
    gbm.insertQuarter();
    gbm.turnCrank();
    
    gbm.refill(2);
    
    gbm.insertQuarter();
    gbm.turnCrank();
    return 0;
}
