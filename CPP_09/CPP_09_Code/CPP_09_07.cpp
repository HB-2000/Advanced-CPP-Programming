#include <iostream>
using namespace std;

class IntPair {
    int first;
    int second;
public:
    IntPair(int a, int b) {
        first = a;
        second = b;
    }
    int sum() {
        return first + second;
    }
    int max() {
        if (first > second)
            return first;
        return second;
    }
};

class DoublePair {
    double first;
    double second;
public:
    DoublePair(double a, double b) {
        first = a;
        second = b;
    }
    double sum() {
        return first + second;
    }
    double max() {
        if (first > second)
            return first;
        return second;
    }
};

int main() {
    IntPair intPair(5, 3);
    DoublePair doublePair(2.5, 4.7);
    cout << "Sum of integer pair: " << intPair.sum() << endl;
    cout << "Maximum of integer pair: " << intPair.max() << endl;
    cout << "Sum of double pair: " << doublePair.sum() << endl;
    cout << "Maximum of double pair: " << doublePair.max() << endl;
    return 0;
}