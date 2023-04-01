#include<iostream>
using namespace std;

class Singleton {
private:
    static Singleton* instance;
    Singleton() {} // private constructor to prevent instantiation outside the class

public:
    Singleton(const Singleton& obj) = delete;

    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void someMethod(string text) {
        cout << text << endl;
    }
};

// Initialize static member of class
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* singleton = Singleton::getInstance();
    singleton->someMethod("You sucessfully access the instance");
    cout << "Address:" << singleton << endl;

    Singleton* a = Singleton::getInstance();
    a->someMethod("have the same address of previous instance");
    cout << "Address:" << a << endl;
}