#include <iostream>
#include <stdexcept>
using namespace std;

// تعریف گره (Node) برای لیست پیوندی
template<typename T>
struct Node {
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

// تعریف کلاس لیست پیوندی یک‌طرفه
template<typename T>
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
    void insertAtHead(int value) {
        Node<T>* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // افزودن به انتهای لیست
    void insertAtTail(T value) {
        Node<T>* newNode = new Node(value);
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
        Node<T>* newNode = new Node(value);
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
    bool remove(int value) {
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
    bool search(int value) const {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == value) return true;
            current = current->next;
        }
        return false;
    }

    // معکوس کردن لیست
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
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
    int getAtPosition(size_t position) const {
        if (position >= size) {
            throw out_of_range("Position out of range");
        }
        Node* current = head;
        for (size_t i = 0; i < position; i++) {
            current = current->next;
        }
        return current->data;
    }

    // نمایش لیست
    void display() const {
        Node* current = head;
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
    SinglyLinkedList list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtHead(0);
    list.insertAtPosition(5, 2);
    cout << "Original list: ";
    list.display(); // خروجی: 0 -> 1 -> 5 -> 2 -> 3 -> nullptr
    cout << "Size: " << list.getSize() << endl; // خروجی: 5
    cout << "Search 5: " << (list.search(5) ? "Found" : "Not found") << endl; // خروجی: Found
    list.remove(2);
    cout << "After removing 2: ";
    list.display(); // خروجی: 0 -> 1 -> 5 -> 3 -> nullptr
    list.removeAtPosition(1);
    cout << "After removing position 1: ";
    list.display(); // خروجی: 0 -> 5 -> 3 -> nullptr
    cout << "Reverse list: ";
    list.reverse();
    list.display(); // خروجی: 3 -> 5 -> 0 -> nullptr
    cout << "Is empty: " << (list.isEmpty() ? "Yes" : "No") << endl; // خروجی: No
    SinglyLinkedList list2 = list; // تست کپی‌ساز
    cout << "Copied list: ";
    list2.display(); // خروجی: 3 -> 5 -> 0 -> nullptr
    list.clear();
    cout << "After clearing original list: ";
    list.display(); // خروجی: List is empty
    return 0;
}