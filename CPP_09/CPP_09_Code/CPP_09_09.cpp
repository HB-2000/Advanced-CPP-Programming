#include <iostream>
#include <string>
using namespace std;

class StringArrayList {
private:
    string* arr;
    int size;
    int capacity;

    void resize() {
        capacity *= 2;
        string* newArr = new string[capacity];
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }
        for (int i = size; i < capacity; i++) {
            newArr[i] = "";
        }
        delete[] arr;
        arr = newArr;
    }

public:
    StringArrayList() {
        capacity = 10;
        size = 0;
        arr = new string[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = "";
        }
    }

    StringArrayList(int cap) {
        if (cap <= 0) {
            capacity = 10;
        } else {
            capacity = cap;
        }
        size = 0;
        arr = new string[capacity];
        for (int i = 0; i < capacity; i++) {
            arr[i] = "";
        }
    }

    StringArrayList(const StringArrayList& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new string[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = "";
        }
    }

    StringArrayList(string* inputArr, int arrSize) {
        if (arrSize <= 0) {
            capacity = 10;
            size = 0;
        } else {
            capacity = arrSize * 2;
            size = arrSize;
        }
        arr = new string[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = inputArr[i];
        }
        for (int i = size; i < capacity; i++) {
            arr[i] = "";
        }
    }

    ~StringArrayList() {
        delete[] arr;
    }

    StringArrayList& operator=(const StringArrayList& other) {
        if (this != &other) {
            delete[] arr;
            capacity = other.capacity;
            size = other.size;
            arr = new string[capacity];
            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
            for (int i = size; i < capacity; i++) {
                arr[i] = "";
        }
        }
        return *this;
    }

    bool operator==(const StringArrayList& other) {
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

    string& operator[](int index) {
        static string dummy = "";
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    const string& operator[](int index) const {
        static string dummy = "";
        if (index < 0 || index >= size) {
            return dummy;
        }
        return arr[index];
    }

    friend ostream& operator<<(ostream& os, const StringArrayList& list) {
        for (int i = 0; i < list.size; i++) {
            os << list.arr[i] << " ";
        }
        return os;
    }

    friend istream& operator>>(istream& is, StringArrayList& list) {
        int newSize;
        is >> newSize;
        if (newSize <= 0) {
            return is;
        }
        if (newSize > list.capacity) {
            delete[] list.arr;
            list.capacity = newSize * 2;
            list.arr = new string[list.capacity];
            for (int i = newSize; i < list.capacity; i++) {
                list.arr[i] = "";
            }
        }
        list.size = newSize;
        for (int i = 0; i < newSize; i++) {
            is >> list.arr[i];
        }
        return is;
    }

    void push_back(string value) {
        if (size == capacity) {
            resize();
        }
        arr[size] = value;
        size++;
    }

    void push_front(string value) {
        if (size == capacity) {
            resize();
        }
        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
    }

    void insert_at(int index, string value) {
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
        arr[size] = "";
    }

    void remove_front() {
        if (size == 0) {
            return;
        }
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
        arr[size] = "";
    }

    void remove_back() {
        if (size == 0) {
            return;
        }
        size--;
        arr[size] = "";
    }
};

int main() {
    StringArrayList list;
    list.push_back("hello");
    list.push_back("world");
    list.push_front("start");
    
    cout << "String list: " << list << endl;
    
    StringArrayList list2;
    list2.push_back("test");
    list2 = list;
    
    cout << "Copied string list: " << list2 << endl;
    cout << "Lists are equal: " << (list == list2) << endl;
    
    list2.insert_at(1, "middle");
    cout << "Modified string list: " << list2 << endl;
    
    return 0;
}
