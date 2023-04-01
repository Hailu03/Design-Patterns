#include <iostream>
#include <vector>

// Observer interface
class Observer {
public:
    virtual void update(int value) = 0;
};

// Subject interface
class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Observer
class ConcreteObserver : public Observer {
public:
    ConcreteObserver(int id) : m_id(id) {}

    void update(int value) {
        std::cout << "Observer " << m_id << " updated with value: " << value << std::endl;
    }

private:
    int m_id;
};

// Concrete Subject
class ConcreteSubject : public Subject {
public:
    void attach(Observer* observer) {
        m_observers.push_back(observer);
    }

    void detach(Observer* observer) {
        for (auto it = m_observers.begin(); it != m_observers.end(); ++it) {
            if (*it == observer) {
                m_observers.erase(it);
                break;
            }
        }
    }

    void notify() {
        for (auto observer : m_observers) {
            observer->update(m_state);
        }
    }

    void setState(int state) {
        m_state = state;
        notify();
    }

private:
    std::vector<Observer*> m_observers;
    int m_state;
};

// Client code
int main() {
    ConcreteSubject* subject = new ConcreteSubject();
    ConcreteObserver* observer1 = new ConcreteObserver(1);
    ConcreteObserver* observer2 = new ConcreteObserver(2);
    ConcreteObserver* observer3 = new ConcreteObserver(3);

    subject->attach(observer1);
    subject->attach(observer2);
    subject->attach(observer3);

    subject->setState(10);

    subject->detach(observer2);

    subject->setState(20);

    return 0;
}