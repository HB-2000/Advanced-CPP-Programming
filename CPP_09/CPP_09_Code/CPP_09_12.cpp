#include <iostream>
#include <string>
using namespace std;

template<typename T, int N>
class Array {
private:
    T arr[N];
public:
    Array() {
        for (int i = 0; i < N; i++) {
            arr[i] = T();
        }
    }
    T& operator[](int index) {
        T dummy = T();
        if (index < 0 || index >= N) {
            return dummy;
        }
        return arr[index];
    }
    const T& operator[](int index) const {
        T dummy = T();
        if (index < 0 || index >= N) {
            return dummy;
        }
        return arr[index];
    }
    void fill(T value) {
        for (int i = 0; i < N; i++) {
            arr[i] = value;
        }
    }
    void print() {
        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }
    }
};

int main() {
    Array<int, 5> intArray;
    intArray.fill(10);
    cout << "Integer array: ";
    intArray.print();
    cout << endl;

    Array<double, 3> doubleArray;
    doubleArray[0] = 1.5;
    doubleArray[1] = 2.7;
    doubleArray[2] = 3.2;
    cout << "Double array: ";
    doubleArray.print();
    cout << endl;

    Array<string, 4> stringArray;
    stringArray.fill("test");
    cout << "String array: ";
    stringArray.print();
    cout << endl;

    Array<char, 6> charArray;
    charArray[0] = 'a';
    charArray[1] = 'b';
    charArray[2] = 'c';
    charArray[3] = 'd';
    charArray[4] = 'e';
    charArray[5] = 'f';
    cout << "Char array: ";
    charArray.print();
    cout << endl;

    return 0;
}
