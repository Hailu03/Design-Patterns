#include <iostream>
#include <memory>

// Product interface
class Animal {
public:
    virtual void speak() = 0;
};

// Concrete Product classes
class Cat : public Animal {
public:
    void speak() {
        std::cout << "Meow!" << std::endl;
    }
};

class Dog : public Animal {
public:
    void speak() {
        std::cout << "Woof!" << std::endl;
    }
};

// Creator interface
class AnimalFactory {
public:
    virtual std::unique_ptr<Animal> createAnimal() = 0;
};

// Concrete Creator classes
class CatFactory : public AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal() {
        return std::make_unique<Cat>();
    }
};

class DogFactory : public AnimalFactory {
public:
    std::unique_ptr<Animal> createAnimal() {
        return std::make_unique<Dog>();
    }
};

// Client code
int main() {
    std::unique_ptr<AnimalFactory> catFactory = std::make_unique<CatFactory>();
    std::unique_ptr<Animal> cat = catFactory->createAnimal();
    cat->speak();

    std::unique_ptr<AnimalFactory> dogFactory = std::make_unique<DogFactory>();
    std::unique_ptr<Animal> dog = dogFactory->createAnimal();
    dog->speak();

    return 0;
}
