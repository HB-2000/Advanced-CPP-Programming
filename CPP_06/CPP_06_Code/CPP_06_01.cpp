#include <iostream>

using namespace std;
int g1 = 10;
int g2 = 20;

int sum(int a, int b) {
    int result = a + b;
    return result;
}

int squre(int a) {
    return a * a;
}

int f(int a, int b, int c) {
    int r1 = sum(a, b);
    int r2 = squre(c);
    return r1 + r2;
}

int main() {
    int a = 1, b = 2, c = 3;
    cout << f(a, b, c) << endl;
}
