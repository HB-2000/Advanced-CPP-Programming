#include <iostream>

class ArrayList {
private:
    int* arr;
    int size;
    int capacity;

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

    ~ArrayList() {
        delete[] arr;
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            return;
        }
        arr[index] = value;
    }

    int get(int index) {
        if (index < 0 || index >= size) {
            return 0;
        }
        return arr[index];
    }
};