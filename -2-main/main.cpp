#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string title;
    int number_of_pages;

public:
    Book() : title(""), number_of_pages(0) {
        cout << "Вызван конструктор по умолчанию\n";
    }

    Book(const string& title, int number_of_pages) {
        setTitle(title);
        setNumberOfPages(number_of_pages);
        cout << "Вызван параметризованный конструктор\n";
    }

    Book(const Book& other) {
        setTitle(other.title);
        setNumberOfPages(other.number_of_pages);
        cout << "Вызван конструктор копирования\n";
    }

    Book(const string& authorName) {
        setTitle(authorName);
        setNumberOfPages(0);
        cout << "Вызван конструктор преобразования\n";
    }

    void setTitle(const string& title) {
        this->title = title;
    }

    void setNumberOfPages(int number_of_pages) {
        if (number_of_pages >= 0) {
            this->number_of_pages = number_of_pages;
        } else {
            cerr << "Количество страниц не может быть отрицательным. Устанавливаем значение 0.\n";
            this->number_of_pages = 0;
        }
    }

    void display() const {
        cout << "Название: " << title << ", Количество страниц: " << number_of_pages << "\n";
    }
};

int main() {
    Book book1;
    cout << "Книга1 (конструктор по умолчанию): ";
    book1.display();

    Book book2("Программирование на C++", 350);
    cout << "Книга2 (параметризованный конструктор): ";
    book2.display();

    Book book3 = book2;
    cout << "Книга3 (конструктор копирования, скопирована из Книги2): ";
    book3.display();

    Book book4 = string("Джон Доу");
    cout << "Книга4 (конструктор преобразования из имени автора): ";
    book4.display();

    book1.setTitle("Структуры данных");
    book1.setNumberOfPages(250);
    cout << "Книга1 после установки значений: ";
    book1.display();

    return 0;
}
