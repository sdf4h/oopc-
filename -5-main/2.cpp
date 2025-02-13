#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    double salary;

public:
    Employee(std::string n, double s) : name(n), salary(s) {}

    virtual void printInfo() const {
        std::cout << "Имя: " << name << ", Зарплата: " << salary << " руб." << std::endl;
    }
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(std::string n, double s, double b) : Employee(n, s), bonus(b) {}

    void printInfo() const override {
        std::cout << "Имя: " << name << ", Зарплата: " << salary << " руб., Надбавка: " << bonus << " руб." << std::endl;
    }
};

int main() {
    Employee employee("Иван", 50000);
    Manager manager("Петр", 70000, 15000);

    Employee* empPtr = &manager;

    employee.printInfo();
    empPtr->printInfo();

    return 0;
}