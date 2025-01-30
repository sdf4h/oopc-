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
    new Seconds(35);
    return 0;
}