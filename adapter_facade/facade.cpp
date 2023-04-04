#include<iostream>
using namespace std;

class SubsystemA {
public:
    void operationA() {
        cout << "Do operation A" << endl;
    }
};

class SubsystemB {
public:
    void operationB() {
        cout << "Do operation B" << endl;
    }
};

class Facade {
public:
    void doSomething() {
        subsystemA.operationA();
        subsystemB.operationB();
    }

private:
    SubsystemA subsystemA;
    SubsystemB subsystemB;
};

int main() {
    Facade facade;
    facade.doSomething();
    return 0;
}
