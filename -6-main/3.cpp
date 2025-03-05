#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Manager;  // Предварительное объявление класса

class Programmer {
private:
    string name;
    Manager* manager;  // Указатель на менеджера
public:
    explicit Programmer(const string& name) : name(name), manager(nullptr) {}

    void setManager(Manager* mgr) {
        manager = mgr;
    }

    string getName() const { return name; }
};

class Manager {
private:
    vector<Programmer*> programmers;  // Список указателей на программистов
public:
    void addProgrammer(Programmer* programmer) {
        programmers.push_back(programmer);
        programmer->setManager(this);  // Устанавливаем связь с менеджером
    }

    void listProgrammers() const {
        cout << "Manager's programmers:" << endl;
        for (const auto& programmer : programmers) {
            cout << "- " << programmer->getName() << endl;
        }
    }
};

// Пример использования
int main() {
    Manager manager;

    Programmer* charlie = new Programmer("Charlie");
    Programmer* dana = new Programmer("Dana");

    manager.addProgrammer(charlie);
    manager.addProgrammer(dana);

    manager.listProgrammers();

    // Уничтожаем программистов вручную
    delete charlie;
    delete dana;

    return 0;
}
