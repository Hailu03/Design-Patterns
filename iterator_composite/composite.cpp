#include <iostream>
#include <vector>
#include<algorithm>

class Component {
public:
    virtual void operation() = 0;
};

class Leaf : public Component {
public:
    void operation() override {
        std::cout << "Leaf operation" << std::endl;
    }
};

class Composite : public Component {
public:
    void add(Component* component) {
        children.push_back(component);
    }

    void remove(Component* component) {
        auto it = std::find(children.begin(), children.end(), component);
        if (it != children.end()) {
            children.erase(it);
        }
    }

    void operation() override {
        std::cout << "Composite operation" << std::endl;

        for (const auto& child : children) {
            child->operation();
        }
    }

private:
    std::vector<Component*> children;
};

int main() {
    Leaf leaf1;
    Leaf leaf2;
    Leaf leaf3;
    Composite composite1;
    Composite composite2;
    composite2.add(&leaf3);

    composite1.add(&leaf1);
    composite1.add(&leaf2);
    composite1.add(&composite2);

    composite1.operation();

    return 0;
}
