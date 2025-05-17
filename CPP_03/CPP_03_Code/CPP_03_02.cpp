#include <iostream>
using namespace std;
int pow (int x, int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= x;
    }
    return result;
}
int main() {
    cout << pow(2,4) + pow(3,5) << endl;
    return 0;
}

