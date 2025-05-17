#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int bookId;
    bool isBorrowed;
    int borrowDays;

public:
    // Constructor
    Book(string t, int id) : title(t), bookId(id), isBorrowed(false), borrowDays(0) {}

    // Destructor
    ~Book() {
        cout << "Book " << bookId << " is being removed." << endl;
    }

    // Getter methods
    string getTitle() { return title; }
    int getBookId() { return bookId; }
    bool getIsBorrowed() { return isBorrowed; }
    int getBorrowDays() { return borrowDays; }

    // Setter methods
    void setTitle(string t) {
        if (!t.empty()) {
            title = t;
            cout << "Title of book " << bookId << " updated to " << title << "." << endl;
        } else {
            cout << "Invalid title for book " << bookId << "." << endl;
        }
    }

    void setBorrowDays(int days) {
        if (days >= 0) {
            borrowDays = days;
        }
    }

    // Other methods
    void borrow(int days) {
        if (!isBorrowed && days >= 0 && days <= 100) {
            isBorrowed = true;
            borrowDays = days;
            cout << "Book " << bookId << " borrowed for " << days << " days." << endl;
        } else {
            cout << "Book " << bookId << " is already borrowed." << endl;
        }
    }

    void returnBook() {
        if (isBorrowed) {
            isBorrowed = false;
            borrowDays = 0;
            cout << "Book " << bookId << " returned." << endl;
        } else {
            cout << "Book " << bookId << " is not borrowed." << endl;
        }
    }

    void extendBorrow(int extraDays) {
        if (isBorrowed && extraDays >= 0 && extraDays <= 100) {
            borrowDays += extraDays;
            cout << "Borrow period for book " << bookId << " extended by " << extraDays
                 << " days, now " << borrowDays << " days." << endl;
        } else {
            cout << "Book " << bookId << " is not borrowed." << endl;
        }
    }

    void checkStatus() {
        if (isBorrowed) {
            cout << "Book " << bookId << " is borrowed for " << borrowDays << " days." << endl;
        } else {
            cout << "Book " << bookId << " is available." << endl;
        }
    }

    void updateTitle(string newTitle) {
        setTitle(newTitle); // Reuse setter logic
    }
};

int main() {
    // Read data for first book
    string title1;
    int bookId1;
    cin >> title1 >> bookId1;

    // Read data for second book
    string title2;
    int bookId2;
    cin >> title2 >> bookId2;

    // Create two Book objects
    Book book1(title1, bookId1);
    Book book2(title2, bookId2);

    // Read number of operations
    int q;
    cin >> q;

    // Process operations
    while (q--) {
        int op, bookNum;
        cin >> op >> bookNum;
        Book& selectedBook = (bookNum == 1) ? book1 : book2;

        if (op == 1) {
            int days;
            cin >> days;
            selectedBook.borrow(days);
        } else if (op == 2) {
            selectedBook.returnBook();
        } else if (op == 3) {
            int extraDays;
            cin >> extraDays;
            selectedBook.extendBorrow(extraDays);
        } else if (op == 4) {
            selectedBook.checkStatus();
        } else if (op == 5) {
            string newTitle;
            cin >> newTitle;
            selectedBook.updateTitle(newTitle);
        }
    }

    return 0;
}