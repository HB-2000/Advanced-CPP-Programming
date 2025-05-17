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

    ArrayList operator+(int value) {
        ArrayList result(size);
        result.size = size;
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] + value;
        }
        return result;
    }

    ArrayList operator-(int value) {
        ArrayList result(size);
        result.size = size;
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] - value;
        }
        return result;
    }

    ArrayList operator*(int value) {
        ArrayList result(size);
        result.size = size;
        for (int i = 0; i < size; i++) {
            result.arr[i] = arr[i] * value;
        }
        return result;
    }

    ArrayList operator/(int value) {
        ArrayList result(size);
        result.size = size;
        for (int i = 0; i < size; i++) {
            if (value != 0) {
                result.arr[i] = arr[i] / value;
            } else {
                result.arr[i] = 0;
            }
        }
        return result;
    }

    friend ArrayList operator+(int value, const ArrayList& list) {
        ArrayList result(list.size);
        result.size = list.size;
        for (int i = 0; i < list.size; i++) {
            result.arr[i] = value + list.arr[i];
        }
        return result;
    }

    friend ArrayList operator-(int value, const ArrayList& list) {
        ArrayList result(list.size);
        result.size = list.size;
        for (int i = 0; i < list.size; i++) {
            result.arr[i] = value - list.arr[i];
        }
        return result;
    }

    friend ArrayList operator*(int value, const ArrayList& list) {
        ArrayList result(list.size);
        result.size = list.size;
        for (int i = 0; i < list.size; i++) {
            result.arr[i] = value * list.arr[i];
        }
        return result;
    }

    friend ArrayList operator/(int value, const ArrayList& list) {
        ArrayList result(list.size);
        result.size = list.size;
        for (int i = 0; i < list.size; i++) {
            if (list.arr[i] != 0) {
                result.arr[i] = value / list.arr[i];
            } else {
                result.arr[i] = 0;
            }
        }
        return result;
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
            list.arr = new int[list.capacity];
            for (int i = newSize; i < list.capacity; i++) {
                list.arr[i] = 0;
            }
        }
        list.size = newSize;
        for (int i = 0; i < newSize; i++) {
            is >> list.arr[i];
        }
        return is;
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

int main() {
    ArrayList a;
    cout << "Enter size and elements for a: ";
    cin >> a;
    cout << "a: " << a << endl;

    ArrayList b = a + 2;
    cout << "a + 2: " << b << endl;

    ArrayList c = 2 + a;
    cout << "2 + a: " << c << endl;

    ArrayList d = a * 2;
    cout << "a * 2: " << d << endl;

    ArrayList e = a / 2;
    cout << "a / 2: " << e << endl;

    ArrayList f;
    cout << "Enter size and elements for f: ";
    cin >> f;
    cout << "f: " << f << endl;
    cout << "a == f: " << (a == f) << endl;

    return 0;
}