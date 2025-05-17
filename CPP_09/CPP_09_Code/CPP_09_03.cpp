#include <iostream>
using namespace std;

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

double findMax(double arr[], int size) {
    double max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

char findMax(char arr[], int size) {
    char max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int main() {
    int intArr[] = {5, 2, 8, 1, 9};
    double doubleArr[] = {3.2, 1.5, 4.7, 2.3};
    char charArr[] = {'e', 'b', 'a', 'd'};

    cout << "Maximum of integer array: " << findMax(intArr, 5) << endl;
    cout << "Maximum of double array: " << findMax(doubleArr, 4) << endl;
    cout << "Maximum of char array: " << findMax(charArr, 4) << endl;

    return 0;
}