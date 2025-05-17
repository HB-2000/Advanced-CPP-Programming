#include <iostream>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swap(double &a, double &b) {
    double temp = a;
    a = b;
    b = temp;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
    int intA = 5, intB = 10;
    double doubleA = 3.14, doubleB = 2.71;
    char charA = 'x', charB = 'y';

    swap(intA, intB);
    swap(doubleA, doubleB);
    swap(charA, charB);

    cout << "Swapped integers: " << intA << " " << intB << endl;
    cout << "Swapped doubles: " << doubleA << " " << doubleB << endl;
    cout << "Swapped chars: " << charA << " " << charB << endl;

    return 0;
}