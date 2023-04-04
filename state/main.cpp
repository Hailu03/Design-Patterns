#include <iostream>
#include <memory>

class Context;

class State {
public:
    virtual void handle(Context* context) = 0;
};

class ConcreteStateA : public State {
public:
    void handle(Context* context) override;
};

class ConcreteStateB : public State {
public:
    void handle(Context* context) override;
};

class Context {
public:
    Context(std::shared_ptr<State> state) : m_state(state) {}
    void setState(std::shared_ptr<State> state) { m_state = state; }
    void handle() { m_state->handle(this); }
private:
    std::shared_ptr<State> m_state;
};

void ConcreteStateA::handle(Context* context) {
    std::cout << "ConcreteStateA handling\n";
    context->setState(std::make_shared<ConcreteStateB>());
}

void ConcreteStateB::handle(Context* context) {
    std::cout << "ConcreteStateB handling\n";
    context->setState(std::make_shared<ConcreteStateA>());
}

int main() {
    std::shared_ptr<State> state = std::make_shared<ConcreteStateA>();
    Context context(state);

    context.handle();
    context.handle();
    context.handle();
    
    return 0;
}
