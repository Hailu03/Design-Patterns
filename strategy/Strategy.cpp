#include <iostream>
#include <vector>

using namespace std;

class Animal {
public:
	virtual void makeSound() = 0;
};

class Dog : public Animal {
public:
	void makeSound() override {
		bark();
	}
	void bark() {
		cout << "Woof" << endl;
	}
};

class Cat : public Animal {
public:
	void makeSound() override {
		meow();
	}
	void meow() {
		cout << "Meow Meow" << endl;
	}
};

class AnimalTest {
public:
	void makeSomeAnimals() {
		Animal* dog = new Dog();
		Animal* cat = new Cat();
		// treat dogs and cats as their supertype, Animal
		vector<Animal*> animals;
		animals.push_back(dog);
		animals.push_back(cat);
		for (auto animal : animals) {
			animal->makeSound(); // can call makeSound on any Animal
		}
		delete dog;
		delete cat;
	}
};

int main() {
	AnimalTest at;
	at.makeSomeAnimals();
	return 0;
}
