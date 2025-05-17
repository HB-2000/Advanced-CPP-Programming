#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int studentId;
    double gpa;

public:
    // Constructor
    Student(string n, int id, double g) : name(n), studentId(id), gpa(g) {}

    // Destructor
    ~Student() {
        cout << "Student with ID " << studentId << " is being deleted." << endl;
    }

    // Getter methods
    string getName() { return name; }
    int getStudentId() { return studentId; }
    double getGpa() { return gpa; }

    // Setter methods
    void setName(string n) { name = n; }
    void setGpa(double g) {
        if (g >= 0 && g <= 20) {
            gpa = g;
            cout << fixed << setprecision(2) << "GPA updated to " << gpa << "." << endl;
        } else {
            cout << "Invalid GPA value." << endl;
        }
    }

    // Other methods
    void updateGpa(double newGpa) {
        setGpa(newGpa); // Reuse setter logic to validate and print
    }

    void isPassing() {
        if (gpa >= 12) {
            cout << "Student is passing." << endl;
        } else {
            cout << "Student is failing." << endl;
        }
    }

    void addBonusGpa(double bonus) {
        if (bonus >= 0 && gpa + bonus <= 20) {
            gpa += bonus;
            cout << fixed << setprecision(2) << "Bonus added, new GPA is " << gpa << "." << endl;
        } else {
            cout << "Invalid bonus value or exceeds GPA limit." << endl;
        }
    }

    void resetStudent() {
        name = "Unknown";
        gpa = 0;
        cout << "Student data reset, GPA is 0." << endl;
    }

    void compareGpa(double value) {
        if (gpa < value) {
            cout << fixed << setprecision(2) << "GPA is less than " << value << "." << endl;
        } else if (gpa == value) {
            cout << fixed << setprecision(2) << "GPA is equal to " << value << "." << endl;
        } else {
            cout << fixed << setprecision(2) << "GPA is greater than " << value << "." << endl;
        }
    }
};

int main() {
    // Read initial student data
    string name;
    int studentId;
    double gpa;
    cin >> name >> studentId >> gpa;

    // Create a Student object
    Student student(name, studentId, gpa);

    // Read number of operations
    int q;
    cin >> q;

    // Process operations
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            double newGpa;
            cin >> newGpa;
            student.updateGpa(newGpa);
        } else if (op == 2) {
            student.isPassing();
        } else if (op == 3) {
            double bonus;
            cin >> bonus;
            student.addBonusGpa(bonus);
        } else if (op == 4) {
            student.resetStudent();
        } else if (op == 5) {
            double value;
            cin >> value;
            student.compareGpa(value);
        }
    }

    return 0;
}