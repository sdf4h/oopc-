#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
private:
    string name;
public:
    explicit Student(const string& name) : name(name) {}
    string getName() const { return name; }
};

class University {
private:
    vector<Student*> students;  // Список указателей на студентов
public:
    void addStudent(Student* student) {
        students.push_back(student);
    }

    void listStudents() const {
        cout << "List of students:" << endl;
        for (const auto& student : students) {
            cout << "- " << student->getName() << endl;
        }
    }
};

// Пример использования
int main() {
    University university;

    Student* alice = new Student("Alice");
    Student* bob = new Student("Bob");

    university.addStudent(alice);
    university.addStudent(bob);

    university.listStudents();

    // Уничтожаем студентов вручную, так как их жизненный цикл независим от университета
    delete alice;
    delete bob;

    return 0;
}
