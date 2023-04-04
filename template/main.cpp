#include <iostream>

class AbstractClass {
public:
    void templateMethod() {
        step1();
        step2();
        step3();
    }

protected:
    virtual void step1() = 0;
    virtual void step2() = 0;
    virtual void step3() = 0;
};

class ConcreteClassA : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClassA: Step 1\n";
    }

    void step2() override {
        std::cout << "ConcreteClassA: Step 2\n";
    }

    void step3() override {
        std::cout << "ConcreteClassA: Step 3\n";
    }
};

class ConcreteClassB : public AbstractClass {
protected:
    void step1() override {
        std::cout << "ConcreteClassB: Step 1\n";
    }

    void step2() override {
        std::cout << "ConcreteClassB: Step 2\n";
    }

    void step3() override {
        std::cout << "ConcreteClassB: Step 3\n";
    }
};

int main() {
    ConcreteClassA a;
    ConcreteClassB b;

    std::cout << "Executing ConcreteClassA:\n";
    a.templateMethod();

    std::cout << "\nExecuting ConcreteClassB:\n";
    b.templateMethod();

    return 0;
}