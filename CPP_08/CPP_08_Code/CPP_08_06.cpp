#include <iostream>
using namespace std;

class ArrayList {
private:
    int* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        for (int i = size; i < capacity; i++) {
            newArr[i] = 0;
        }
        delete[] arr;
        arr = newArr;
    }

public:
    ArrayList() {
        capacity = 10;
        size = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    ArrayList(int cap) {
        if (cap <= 0) {
            capacity = 10;
        } else {
            capacity = cap;
        }
        size = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    ArrayList(const ArrayList& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    ArrayList(int* inputArr, int arrSize) {
        if (arrSize <= 0) {
            capacity = 10;
            size = 0;
        } else {
            capacity = arrSize * 2;
            size = arrSize;
        }
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = 0;
        }
    }

    ~ArrayList() {
        delete[] arr;
    }

    ArrayList& operator=(const ArrayList& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new int[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
            for (int i = size; i < capacity; i++) {
                arr[i] = 0;
            }
        }
        return *this;
    }

    ArrayList operator+(const ArrayList& other) {
        int minSize = size < other.size ? size : other.size;
        ArrayList result(minSize);
        result.size = minSize;
        for (int i = 0; i < minSize; i++) {
            result.arr[i] = arr[i] + other.arr[i];
        }
        return result;
    }

    ArrayList operator-(const ArrayList& other) {
        int minSize = size < other.size ? size : other.size;
        ArrayList result(minSize);
        result.size = minSize;
        for (int i = 0; i < minSize; i++) {
            result.arr[i] = arr[i] - other.arr[i];
        }
        return result;
    }

    ArrayList operator*(const ArrayList& other) {
        int minSize = size < other.size ? size : other.size;
        ArrayList result(minSize);
        result.size = minSize;
        for (int i = 0; i < minSize; i++) {
            result.arr[i] = arr[i] * other.arr[i];
        }
        return result;
    }

    ArrayList operator/(const ArrayList& other) {
        int minSize = size < other.size ? size : other.size;
        ArrayList result(minSize);
        result.size = minSize;
        for (int i = 0; i < minSize; i++) {
            if (other.arr[i] != 0) {
                result.arr[i] = arr[i] / other.arr[i];
            } else {
                result.arr[i] = 0;
            }
        }
        return result;
    }

    bool operator==(const ArrayList& other) {
        if (size != other.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            if (arr[i] != other.arr[i]) {
                return false;
            }
        }
        return true;
    }

    int& operator[](int index) {
        static int dummy = 0;
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    const int& operator[](int index) const {
        static int dummy = 0;
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    void push_back(int value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    void push_front(int value) {
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insert_at(int index, int value) {
        if (index < 0 || index > size) {
            return;
        }
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }
        arr[index] = value;
        size++;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) {
            return;
        }
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        arr[size] = 0;
    }

    void remove_front() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        arr[size] = 0;
    }

    void remove_back() {
        if (size == 0) {
            return;
        }
        size--;
        arr[size] = 0;
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int sum() {
        int total = 0;
        for (int i = 0; i < size; i++) {
            total += arr[i];
        }
        return total;
    }

    double avg() {
        if (size == 0) {
            return 0.0;
        }
        return static_cast<double>(sum()) / size;
    }
};