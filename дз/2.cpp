#include <iostream>
using namespace std;

class Seconds {
private:
    int seconds;
public:
    Seconds(int s) : seconds(s) {}

    int getSeconds() const {
        return seconds;
    }
};

int main() {
    Seconds *s1 = new Seconds(30);
    Seconds *s2 = new Seconds(45);

    cout << "s1 seconds: " << s1->getSeconds() << endl;
    cout << "s2 seconds: " << s2->getSeconds() << endl;

    delete s1;
    delete s2;

    return 0;
}