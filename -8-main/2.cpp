#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class IObserver {
public:
    virtual void update(float price) = 0;
    virtual ~IObserver() = default;
};

class Investor : public IObserver {
private:
    std::string name;
public:
    Investor(const std::string& name) : name(name) {}

    void update(float price) override {
        std::cout << "Investor " << name << " notified. New price: " << price << std::endl;
    }
};

class Stock {
private:
    std::vector<std::shared_ptr<IObserver>> observers;
    float price;
public:
    Stock(float initialPrice) : price(initialPrice) {}

    void attach(std::shared_ptr<IObserver> observer) {
        observers.push_back(observer);
    }

    void detach(std::shared_ptr<IObserver> observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void setPrice(float newPrice) {
        if (price != newPrice) {
            price = newPrice;
            notify();
        }
    }

    void notify() {
        for (const auto& observer : observers) {
            observer->update(price);
        }
    }
};

int main() {
    Stock stock(100.0f);
    std::shared_ptr<IObserver> investor1 = std::make_shared<Investor>("Alice");
    std::shared_ptr<IObserver> investor2 = std::make_shared<Investor>("Bob");

    stock.attach(investor1);
    stock.attach(investor2);

    stock.setPrice(105.0f);
    stock.setPrice(110.0f);
    stock.detach(investor1);
    stock.setPrice(95.0f);

    return 0;
}