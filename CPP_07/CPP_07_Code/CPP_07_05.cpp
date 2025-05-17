#include <iostream>

using namespace std;

class DynamicInt {
private:
    int* value;

public:
    // Constructor
    DynamicInt(int v) {
        value = new int;
        *value = v;
    }

    // Destructor
    ~DynamicInt() {
        delete value;
    }

    // Copy Constructor
    DynamicInt(const DynamicInt& other) {
        value = new int;
        *value = *(other.value);
    }

    // Copy Assignment Operator
    DynamicInt& operator=(const DynamicInt& other) {
        if (this != &other) {
            delete value;
            value = new int;
            *value = *(other.value);
        }
        return *this;
    }

    int getValue() const {
        return *value;
    }
    void setValue(int v) { *value = v; }

};


int main() {

}
