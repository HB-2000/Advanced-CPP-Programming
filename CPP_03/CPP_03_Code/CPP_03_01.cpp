#include <iostream>
using namespace std;

int main() {
    int p1 = 1;
    for (int i = 0; i < 4; ++i) {
        p1 = p1 * 2;
    }
    int p2 = 1;
    for (int i = 0; i < 5; ++i) {
        p2 = p2 * 3;
    }
    cout << p1 + p2;
    return 0;
}
