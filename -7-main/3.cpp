#include <iostream>
#include <vector>
#include <memory>

class Observer {
public:
    virtual void update(int value) = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    void attach(std::shared_ptr<Observer> observer) {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<Observer> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notify(int value) {
        for (const auto& observer : observers) {
            observer->update(value);
        }
    }

private:
    std::vector<std::shared_ptr<Observer>> observers;
};

class ConcreteObserver : public Observer {
public:
    ConcreteObserver(std::string name) : name(name) {}

    void update(int value) override {
        std::cout << "Observer " << name << " received value: " << value << std::endl;
    }

private:
    std::string name;
};

int main() {
    std::shared_ptr<Subject> subject = std::make_shared<Subject>();
    std::shared_ptr<ConcreteObserver> observer1 = std::make_shared<ConcreteObserver>("A");
    std::shared_ptr<ConcreteObserver> observer2 = std::make_shared<ConcreteObserver>("B");

    subject->attach(observer1);
    subject->attach(observer2);

    subject->notify(10);
    subject->notify(20);

    subject->detach(observer1);
    
    subject->notify(30);

    return 0;
}