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

    ArrayList b(5);
    b.push_back(1);
    b.push_back(2);
    b.push_back(3);
    cout << "b (capacity 5, manual): " << b << endl;

    int arr[] = {4, 5, 6};
    ArrayList c(arr, 3);
    cout << "c (from array [4,5,6]): " << c << endl;

    ArrayList d = b;
    cout << "d (copy of b): " << d << endl;

    d[1] = 10;
    cout << "d after d[1] = 10: " << d << endl;
    cout << "d[1]: " << d[1] << endl;

    a.push_back(7);
    cout << "a after push_back(7): " << a << endl;

    a.push_front(0);
    cout << "a after push_front(0): " << a << endl;

    a.insert_at(2, 99);
    cout << "a after insert_at(2, 99): " << a << endl;

    a.remove_at(1);
    cout << "a after remove_at(1): " << a << endl;

    a.remove_front();
    cout << "a after remove_front: " << a << endl;

    a.remove_back();
    cout << "a after remove_back: " << a << endl;

    ArrayList e = a + b;
    cout << "a + b: " << e << endl;

    ArrayList f = a - b;
    cout << "a - b: " << f << endl;

    ArrayList g = a * b;
    cout << "a * b: " << g << endl;

    ArrayList h = a / b;
    cout << "a / b: " << h << endl;

    ArrayList i = a + 2;
    cout << "a + 2: " << i << endl;

    ArrayList j = 2 + a;
    cout << "2 + a: " << j << endl;

    ArrayList k = a - 2;
    cout << "a - 2: " << k << endl;

    ArrayList l = 2 - a;
    cout << "2 - a: " << l << endl;

    ArrayList m = a * 2;
    cout << "a * 2: " << m << endl;

    ArrayList n = 2 * a;
    cout << "2 * a: " << n << endl;

    ArrayList o = a / 2;
    cout << "a / 2: " << o << endl;

    ArrayList p = 2 / a;
    cout << "2 / a: " << p << endl;

    cout << "a == b: " << (a == b) << endl;
    cout << "b == d: " << (b == d) << endl;

    cout << "Sum of a: " << a.sum() << endl;
    cout << "Average of a: " << a.avg() << endl;

    return 0;
}