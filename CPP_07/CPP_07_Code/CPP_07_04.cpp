#include <iostream>

using namespace std;

class DynamicInt {
private:
    int *value;

public:
    DynamicInt(int v) {
        value = new int;
        *value = v;
    }

    int getValue() { return *value; }
    void setValue(int v) { *value = v; }

    // DynamicInt& operator=(const DynamicInt& other) {
    //     if (this != &other) {
    //         delete value;
    //         value = new int;
    //         *value = *(other.value);
    //     }
    //     return *this;
    // }
};

int main() {
    DynamicInt x(10);
    DynamicInt y(20);
    y = x;
    y.setValue(30);
    cout << x.getValue() << endl;
}
