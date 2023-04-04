#include <iostream>
#include <vector>
#include <memory>

// Iterator interface
class Iterator {
public:
    virtual bool hasNext() = 0;
    virtual int next() = 0;
};

// Concrete Iterator class for iterating over a vector
class VectorIterator : public Iterator {
public:
    VectorIterator(std::vector<int> v) : vec(v), index(0) {}
    bool hasNext() {
        return index < vec.size();
    }
    int next() {
        int val = vec[index];
        index++;
        return val;
    }
private:
    std::vector<int> vec;
    int index;
};

// Aggregate interface
class Aggregate {
public:
    virtual std::unique_ptr<Iterator> createIterator() = 0;
};

// Concrete Aggregate class for a vector
class VectorAggregate : public Aggregate {
public:
    VectorAggregate(std::vector<int> v) : vec(v) {}
    std::unique_ptr<Iterator> createIterator() {
        return std::make_unique<VectorIterator>(vec);
    }
private:
    std::vector<int> vec;
};

// Client code
int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    std::unique_ptr<Aggregate> agg = std::make_unique<VectorAggregate>(v);
    std::unique_ptr<Iterator> it = agg->createIterator();
    while (it->hasNext()) {
        std::cout << it->next() << std::endl;
    }
    return 0;
}