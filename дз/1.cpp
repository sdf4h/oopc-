#include <iostream>
using namespace std;

class Seconds {
private:
    int seconds;
public:
    Seconds(int s) : seconds(s) {}

    void setSeconds(int s) {
        seconds = s;
    }

    int getSeconds() const {
        return seconds;
    }

    bool operator==(const Seconds& other) const {
        return seconds == other.seconds;
    }
};

void modifySeconds(Seconds &s) {
    s.setSeconds(s.getSeconds() + 10);
}

int main() {
    Seconds s1(30);
    Seconds s2(20);
    
    modifySeconds(s1);
    
    cout << "s1 seconds: " << s1.getSeconds() << endl;
    cout << "s2 seconds: " << s2.getSeconds() << endl;

    if (s1 == s2) {
        cout << "s1 и s2 равны." << endl;
    } else {
        cout << "s1 и s2 не равны." << endl;
    }

    return 0;
}