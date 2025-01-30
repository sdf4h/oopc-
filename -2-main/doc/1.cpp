#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    int year;
    int numPages;

public:

    Book(string title, string author, int year, int numPages) {
        title = title;
        author = author;
        year = year;
        numPages = numPages;
    }


    void changeNumPages(int newNumPages) {
        numPages = newNumPages;
    }

    void getInfo() {
        cout << "название: " << title << endl;
        cout << "автор: " << author << endl;
        cout << "год выпуска: " << year << endl;
        cout << "сколько страниц: " << numPages << endl;
    }
};

int main() {

    Book myBook("убийца данила", "камиль Х", 1960, 281);


    cout << "стоковая:" << endl;
    myBook.getInfo();


    myBook.changeNumPages(320);


    cout << "\nапдейт:" << endl;
    myBook.getInfo();

    return 0;
}