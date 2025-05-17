#include <iostream>
using namespace std;

int max(int a, int b) {
    if (a > b)
        return a;
    return b;
}

double max(double a, double b) {
    if (a > b)
        return a;
    return b;
}

char max(char a, char b) {
    if (a > b)
        return a;
    return b;
}

int main() {
    int intA = 7, intB = 3;
    double doubleA = 5.6, doubleB = 8.2;
    char charA = 'c', charB = 'a';

    cout << "Maximum of integers: " << max(intA, intB) << endl;
    cout << "Maximum of doubles: " << max(doubleA, doubleB) << endl;
    cout << "Maximum of chars: " << max(charA, charB) << endl;
    
    return 0;
}