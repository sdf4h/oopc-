#include <iostream>
using namespace std;

class Engine {
public:
    void run() {
        cout << "Engine is running." << endl;
    }
};

class Car {
private:
    Engine engine;  // Композиция: двигатель является частью автомобиля
public:
    Car() {
        cout << "Car created." << endl;
    }

    ~Car() {
        cout << "Car destroyed." << endl;
    }

    void start() {
        cout << "Car is starting." << endl;
        engine.run();
    }
};

// Пример использования
int main() {
    Car car;
    car.start();
    return 0;
}
