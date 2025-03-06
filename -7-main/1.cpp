#include <iostream>
#include <memory>

class Singleton {
public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance; 
        return instance;
    }

    void someBusinessLogic() {
        std::cout << "Выполнение метода someBusinessLogic" << std::endl;
    }

private:
    Singleton() {
        std::cout << "Создание экземпляра Singleton" << std::endl;
    }
};

int main() {

    Singleton::getInstance().someBusinessLogic();
    return 0;
}