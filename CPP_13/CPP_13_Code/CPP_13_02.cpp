#include <iostream>
#include <stdexcept>
using namespace std;

// تعریف گره (Node) برای لیست پیوندی به صورت قالب
template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// تعریف کلاس لیست پیوندی یک‌طرفه به صورت قالب
template <typename T>
class SinglyLinkedList {
private:
    Node<T>* head;
    size_t size;

    // کپی عمیق لیست
    void deepCopy(const SinglyLinkedList& other) {
        head = nullptr;
        size = 0;
        Node<T>* current = other.head;
        while (current != nullptr) {
            insertAtTail(current->data);
            current = current->next;
        }
    }

public:
    // سازنده پیش‌فرض
    SinglyLinkedList() : head(nullptr), size(0) {}

    // کپی‌ساز
    SinglyLinkedList(const SinglyLinkedList& other) : head(nullptr), size(0) {
        deepCopy(other);
    }

    // عملگر تخصیص
    SinglyLinkedList& operator=(const SinglyLinkedList& other) {
        if (this != &other) {
            clear();
            deepCopy(other);
        }
        return *this;
    }

    // دفع‌کننده
    ~SinglyLinkedList() {
        clear();
    }

    // پاک کردن کل لیست
    void clear() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    // افزودن به ابتدای لیست
    void insertAtHead(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // افزودن به انتهای لیست
    void insertAtTail(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    // افزودن در موقعیت خاص
    void insertAtPosition(T value, size_t position) {
        if (position > size) {
            throw out_of_range("Position out of range");
        }
        if (position == 0) {
            insertAtHead(value);
            return;
        }
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current = head;
        for (size_t i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                throw out_of_range("Position out of range");
            }
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        size++;
    }

    // حذف اولین گره با مقدار مشخص
    bool remove(T value) {
        if (head == nullptr) return false;

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return true;
        }

        Node<T>* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }
        if (current->next == nullptr) return false;

        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
        return true;
    }

    // حذف گره در موقعیت خاص
    void removeAtPosition(size_t position) {
        if (position >= size) {
            throw out_of_range("Position out of range");
        }
        if (position == 0) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            size--;
            return;
        }
        Node<T>* current = head;
        for (size_t i = 0; i < position - 1; i++) {
            if (current == nullptr) {
                throw out_of_range("Position out of range");
            }
            current = current->next;
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        delete temp;
        size--;
    }

    // جستجوی مقدار
    bool search(T value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // معکوس کردن لیست
    void reverse() {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    // بررسی خالی بودن لیست
    bool isEmpty() const {
        return head == nullptr;
    }

    // گرفتن اندازه لیست
    size_t getSize() const {
        return size;
    }

    // گرفتن مقدار گره در موقعیت خاص
    T getAtPosition(size_t position) const {
        if (position >= size) {
            throw out_of_range("Position out of range");
        }
        Node<T>* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    // نمایش لیست
    void display() const {
        Node<T>* current = head;
        if (current == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
};

// تابع main برای تست کلاس
int main() {
    // تست با نوع داده int
    SinglyLinkedList<int> intList;
    intList.insertAtTail(1);
    intList.insertAtTail(2);
    intList.insertAtTail(3);
    intList.insertAtHead(0);
    intList.insertAtPosition(5, 2);
    cout << "Integer list: ";
    intList.display(); // خروجی: 0 -> 1 -> 5 -> 2 -> 3 -> nullptr
    cout << "Size: " << intList.getSize() << endl; // خروجی: 5
    cout << "Search 5: " << (intList.search(5) ? "Found" : "Not found") << endl; // خروجی: Found
    intList.remove(2);
    cout << "After removing 2: ";
    intList.display(); // خروجی: 0 -> 1 -> 5 -> 3 -> nullptr
    intList.removeAtPosition(1);
    cout << "After removing position 1: ";
    intList.display(); // خروجی: 0 -> 5 -> 3 -> nullptr
    cout << "Reverse list: ";
    intList.reverse();
    intList.display(); // خروجی: 3 -> 5 -> 0 -> nullptr
    cout << "Is empty: " << (intList.isEmpty() ? "Yes" : "No") << endl; // خروجی: No
    SinglyLinkedList<int> intList2 = intList; // تست کپی‌ساز
    cout << "Copied integer list: ";
    intList2.display(); // خروجی: 3 -> 5 -> 0 -> nullptr
    intList.clear();
    cout << "After clearing integer list: ";
    intList.display(); // خروجی: List is empty

    // تست با نوع داده double
    SinglyLinkedList<double> doubleList;
    doubleList.insertAtTail(1.1);
    doubleList.insertAtTail(2.2);
    doubleList.insertAtHead(0.5);
    cout << "\nDouble list: ";
    doubleList.display(); // خروجی: 0.5 -> 1.1 -> 2.2 -> nullptr
    cout << "Size: " << doubleList.getSize() << endl; // خروجی: 3
    cout << "Search 1.1: " << (doubleList.search(1.1) ? "Found" : "Not found") << endl; // خروجی: Found

    // تست با نوع داده string
    SinglyLinkedList<string> stringList;
    stringList.insertAtTail("one");
    stringList.insertAtTail("two");
    stringList.insertAtHead("zero");
    cout << "\nString list: ";
    stringList.display(); // خروجی: zero -> one -> two -> nullptr
    cout << "Size: " << stringList.getSize() << endl; // خروجی: 3
    stringList.reverse();
    cout << "Reversed string list: ";
    stringList.display(); // خروجی: two -> one -> zero -> nullptr

    return 0;
}