#include <iostream>
using namespace std;

class TimePeriod {
public:
    int начало;
    int конец;

    int продолжительность() const {
        return конец - начало;
    }

    bool положительный() const {
        return конец > начало;
    }
};

int main() {
    TimePeriod период;
    период.начало = 10;
    период.конец = 15;

    cout << "Продолжительность: " << период.продолжительность() << " часов" << endl;
    if (период.положительный()) {
        cout << "Период положительный (конец позже начала)." << endl;
    } else {
        cout << "Период отрицательный (начало позже конца)." << endl;
    }

    return 0;
}