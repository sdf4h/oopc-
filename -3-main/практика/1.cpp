#include <iostream>

using namespace std;

class Seconds {
private:
    int seconds;
public:
    Seconds(int sec) : seconds(sec) {}

    void display() const {
        cout << "Время в секундах: " << seconds << endl;
    }
};

int main() {
    int n;
    cout << "Введите количество объектов Seconds: ";
    cin >> n;

    Seconds* secondsArray = new Seconds[n];

    for (int i = 0; i < n; ++i) {
        int timeInSeconds;
        cout << "Введите время для объекта " << (i + 1) << ": ";
        cin >> timeInSeconds;
        secondsArray[i] = Seconds(timeInSeconds);
    }

    for (int i = 0; i < n; ++i) {
        secondsArray[i].display();
    }

    delete[] secondsArray;

    return 0;
}