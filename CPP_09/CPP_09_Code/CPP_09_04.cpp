#include <iostream>
using namespace std;

void sort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void sort(double arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

void sort(char arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

int main() {
    int intArr[] = {5, 2, 8, 1, 9};
    double doubleArr[] = {3.2, 1.5, 4.7, 2.3};
    char charArr[] = {'e', 'b', 'a', 'd', 'c'};
    
    sort(intArr, 5);
    sort(doubleArr, 4);
    sort(charArr, 5);
    
    cout << "Sorted integer array: ";
    for (int i = 0; i < 5; i++)
        cout << intArr[i] << " ";
    cout << endl;
    
    cout << "Sorted double array: ";
    for (int i = 0; i < 4; i++)
        cout << doubleArr[i] << " ";
    cout << endl;
    
    cout << "Sorted char array: ";
    for (int i = 0; i < 5; i++)
        cout << charArr[i] << " ";
    cout << endl;
    
    return 0;
}