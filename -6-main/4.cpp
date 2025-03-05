#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    double salary;

public:
    Employee(const string& name, double salary) : name(name), salary(salary) {}

    virtual void printInfo() const {
        cout << "Employee Name " << name << ", Salary " << salary << endl;
    }

    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    double bonus;

public:
    Manager(const string& name, double salary, double bonus)
        : Employee(name, salary), bonus(bonus) {}

    void printInfo() const override {
        cout << "Manager Name " << name << ", Salary " << salary << ", Bonus " << bonus << endl;
    }
};

// Пример использования
int main() {
    Employee* employee = new Employee("John", 50000);
    Employee* manager = new Manager("Alice", 70000, 15000);

    employee->printInfo();
    manager->printInfo();

    delete employee;
    delete manager;

    return 0;
}
