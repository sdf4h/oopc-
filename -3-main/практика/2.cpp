#include <iostream>
#include <vector>

using namespace std;

class Seconds {
private:
    int seconds;
public:
    Seconds(int sec) : seconds(sec) {}

    void display() const {
        cout << "Время в секундах: " << seconds << endl;
    }

    void setSeconds(int sec) {
        seconds = sec;
    }
};

int main() {
    vector<Seconds> secondsVector;
    int n;

    cout << "Введите количество объектов Seconds для добавления: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int timeInSeconds;
        cout << "Введите время для объекта " << (i + 1) << ": ";
        cin >> timeInSeconds;
        secondsVector.emplace_back(timeInSeconds);
    }

    for (const auto& sec : secondsVector) {
        sec.display();
    }

    int index, newTime;
    cout << "Введите индекс объекта для изменения (от 0 до " << n - 1 << "): ";
    cin >> index;
    if (index >= 0 && index < n) {
        cout << "Введите новое время в секундах: ";
        cin >> newTime;
        secondsVector[index].setSeconds(newTime);
    } else {
        cout << "Неверный индекс!" << endl;
    }

    cout << "Обновленные значения:" << endl;
    for (const auto& sec : secondsVector) {
        sec.display();
    }

    return 0;
}