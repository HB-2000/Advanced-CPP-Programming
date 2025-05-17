
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class ArrayList {
private:
    T* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        T* newArr = new T[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        for (int i = size; i < capacity; i++) {
            newArr[i] = T();
        }
        delete[] arr;
        arr = newArr;
    }

public:
    ArrayList() {
        capacity = 10;
        size = 0;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = T();
        }
    }

    ArrayList(int cap) {
        if (cap <= 0) {
            capacity = 10;
        } else {
            capacity = cap;
        }
        size = 0;
        arr = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = T();
        }
    }

    ArrayList(const ArrayList& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = T();
        }
    }

    ArrayList(T* inputArr, int arrSize) {
        if (arrSize <= 0) {
            capacity = 10;
            size = 0;
        } else {
            capacity = arrSize * 2;
            size = arrSize;
        }
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = T();
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
            arr = new T[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
            for (int i = size; i < capacity; i++) {
                arr[i] = T();
            }
        }
        return *this;
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

    T& operator[](int index) {
        static T dummy = T();
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    const T& operator[](int index) const {
        static T dummy = T();
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    friend ostream& operator<<(ostream& os, const ArrayList& list) {
        for (int i = 0; i < list.size; i++) {
            os << list.arr[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, ArrayList& list) {
        int newSize;
        is >> newSize;
        if (newSize <= 0) {
            return is;
        }
        if (newSize > list.capacity) {
            delete[] list.arr;
            list.capacity = newSize * 2;
            list.arr = new T[list.capacity];
            for (int i = newSize; i < list.capacity; i++) {
                list.arr[i] = T();
            }
        }
        list.size = newSize;
        for (int i = 0; i < newSize; i++) {
            is >> list.arr[i];
        }
        return is;
    }

    void push_back(T value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    void push_front(T value) {
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insert_at(int index, T value) {
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
        arr[size] = T();
    }

    void remove_front() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        arr[size] = T();
    }

    void remove_back() {
        if (size == 0) {
            return;
        }
        size--;
        arr[size] = T();
    }
};

int main() {
    ArrayList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_front(0);

    cout << "Integer list: " << intList << endl;

    ArrayList<string> stringList;
    stringList.push_back("hello");
    stringList.push_back("world");
    stringList.push_front("start");

    cout << "String list: " << stringList << endl;

    ArrayList<int> intList2;
    intList2.push_back(1);
    intList2 = intList;

    cout << "Copied integer list: " << intList2 << endl;
    cout << "Lists are equal: " << (intList == intList2) << endl;

    stringList.insert_at(1, "middle");
    cout << "Modified string list: " << stringList << endl;
    
    return 0;
}
