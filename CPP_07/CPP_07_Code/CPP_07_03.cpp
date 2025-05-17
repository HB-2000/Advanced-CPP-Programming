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

    // DynamicInt(const DynamicInt& other) {
    //     value = new int;
    //     *value = *(other.value);
    // }


};
void changeValue(DynamicInt y, int v) {
    y.setValue(v);
}
int main() {
    DynamicInt x(10);
    changeValue(x, 20);
    cout << x.getValue() << endl;
    return 0;
}
