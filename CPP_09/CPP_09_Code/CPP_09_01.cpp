#include <iostream>
#include <string>
using namespace std;

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(double arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printArray(string arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.7, 3.2, 4.9};
    string stringArr[] = {"Hello", "World", "C++"};

    printArray(intArr, 5);
    printArray(doubleArr, 4);
    printArray(stringArr, 3);


    return 0;
}