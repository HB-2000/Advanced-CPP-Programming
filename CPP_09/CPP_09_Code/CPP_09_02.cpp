#include <iostream>
using namespace std;

int sum(int arr[], int size) {
    int result = 0;
    for (int i = 0; i < size; i++)
        result += arr[i];
    return result;
}

double sum(double arr[], int size) {
    double result = 0;
    for (int i = 0; i < size; i++)
        result += arr[i];
    return result;
}



int main() {
    int intArr[] = {1, 2, 3, 4, 5};
    double doubleArr[] = {1.5, 2.5, 3.5};

    cout << "Sum of integer array: " << sum(intArr, 5) << endl;
    cout << "Sum of double array: " << sum(doubleArr, 3) << endl;

    return 0;
}