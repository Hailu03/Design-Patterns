#include <iostream>
#include <string>

// Component interface
class Beverage {
public:
    virtual std::string getDescription() const = 0;
    virtual double getCost() const = 0;
};

// Concrete Component
class Espresso : public Beverage {
public:
    std::string getDescription() const {
        return "Espresso";
    }

    double getCost() const {
        return 1.99;
    }
};

// Decorator
class CondimentDecorator : public Beverage {
public:
    CondimentDecorator(Beverage* beverage) : m_beverage(beverage) {}

    std::string getDescription() const {
        return m_beverage->getDescription();
    }

    double getCost() const {
        return m_beverage->getCost();
    }

private:
    Beverage* m_beverage;
};

// Concrete Decorator
class Milk : public CondimentDecorator {
public:
    Milk(Beverage* beverage) : CondimentDecorator(beverage) {}

    std::string getDescription() const {
        return CondimentDecorator::getDescription() + ", Milk";
    }

    double getCost() const {
        return CondimentDecorator::getCost() + 0.10;
    }
};

// Client code
int main() {
    Beverage* beverage = new Espresso();
    std::cout << "Beverage: " << beverage->getDescription() << ", Cost: $" << beverage->getCost() << std::endl;

    Beverage* milkBeverage = new Milk(beverage);
    std::cout << "Beverage: " << milkBeverage->getDescription() << ", Cost: $" << milkBeverage->getCost() << std::endl;

    return 0;
}
