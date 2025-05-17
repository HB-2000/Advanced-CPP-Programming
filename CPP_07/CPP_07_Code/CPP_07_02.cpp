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

    ~DynamicInt() {
        delete value;
    }
};

int main() {
    DynamicInt d(10);
    cout << d.getValue() << endl;
    return 0;
}
