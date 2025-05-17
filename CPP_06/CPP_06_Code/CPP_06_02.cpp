#include <iostream>

using namespace std;
int g1 = 15;
int g2 = 25;

int mult(int x, int y) {
    int result = x * y;
    return result;
}

int cube(int x) {
    return x * x * x;
}

int f(int x, int y, int z) {
    int m2 = cube(z); // ابتدا cube فراخوانی می‌شود
    int m1 = mult(x, y); // سپس multiply
    return m1 + m2;
}

int main() {
    int x = 2, y = 3, z = 4;
    cout << mult(x, y) << endl;
    cout << cube(x) << endl;
    cout << f(x, y, z) << endl;
    return 0;
}