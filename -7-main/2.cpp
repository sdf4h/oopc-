#include <iostream>
#include <memory>

class Engine {
public:
    virtual void start() = 0;
    virtual ~Engine() = default;
};

class Car {
public:
    virtual void drive() = 0;
    virtual ~Car() = default;
};

class CityEngine : public Engine {
public:
    void start() override {
        std::cout << "Городской двигатель запущен." << std::endl;
    }
};

class TruckEngine : public Engine {
public:
    void start() override {
        std::cout << "Грузовой двигатель запущен." << std::endl;
    }
};

class CityCar : public Car {
public:
    CityCar(std::shared_ptr<Engine> engine) : engine(engine) {}

    void drive() override {
        engine->start();
        std::cout << "Городской автомобиль едет." << std::endl;
    }

private:
    std::shared_ptr<Engine> engine;
};

class Truck : public Car {
public:
    Truck(std::shared_ptr<Engine> engine) : engine(engine) {}

    void drive() override {
        engine->start();
        std::cout << "Грузовой автомобиль едет." << std::endl;
    }

private:
    std::shared_ptr<Engine> engine;
};

class AbstractFactory {
public:
    virtual std::shared_ptr<Car> createCar() = 0;
    virtual std::shared_ptr<Engine> createEngine() = 0;
    virtual ~AbstractFactory() = default;
};

class CityFactory : public AbstractFactory {
public:
    std::shared_ptr<Car> createCar() override {
        return std::make_shared<CityCar>(createEngine());
    }

    std::shared_ptr<Engine> createEngine() override {
        return std::make_shared<CityEngine>();
    }
};

class TruckFactory : public AbstractFactory {
public:
    std::shared_ptr<Car> createCar() override {
        return std::make_shared<Truck>(createEngine());
    }

    std::shared_ptr<Engine> createEngine() override {
        return std::make_shared<TruckEngine>();
    }
};

int main() {
    std::shared_ptr<AbstractFactory> cityFactory = std::make_shared<CityFactory>();
    std::shared_ptr<Car> cityCar = cityFactory->createCar();
    cityCar->drive();

    std::shared_ptr<AbstractFactory> truckFactory = std::make_shared<TruckFactory>();
    std::shared_ptr<Car> truck = truckFactory->createCar();
    truck->drive();

    return 0;
}