#include <iostream>
#include <string>
using namespace std;

// Базовый класс Person
class Person {
protected:
    string name;
    int age;

public:
    Person(const string& name, int age) : name(name), age(age) {}

    virtual void printInfo() const {
        cout << "Name " << name << ", Age " << age << endl;
    }

    virtual ~Person() {}
};

// Класс Student, наследующий Person
class Student : virtual public Person {
protected:
    string university;

public:
    Student(const string& name, int age, const string& university)
        : Person(name, age), university(university) {}

    void printInfo() const override {
        cout << "Name " << name << ", Age " << age << ", University " << university << endl;
    }
};

// Класс Worker, наследующий Person
class Worker : virtual public Person {
protected:
    string company;

public:
    Worker(const string& name, int age, const string& company)
        : Person(name, age), company(company) {}

    void printInfo() const override {
        cout << "Name " << name << ", Age " << age << ", Company " << company << endl;
    }
};

// Класс Intern, наследующий и Student, и Worker
class Intern : public Student, public Worker {
public:
    Intern(const string& name, int age, const string& university, const string& company)
        : Person(name, age), Student(name, age, university), Worker(name, age, company) {}

    void printInfo() const override {
        cout << "Name " << name << ", Age " << age 
             << ", University " << university << ", Company " << company << endl;
    }
};

// Пример использования
int main() {
    Intern intern("Charlie", 21, "MIT", "TechCorp");
    intern.printInfo();
    
    return 0;
}
