#include <iostream>
#include <string>
using namespace std;

int main() {

    string name1;
    int age1;
    float gpa1;
    int id1;

    string name2;
    int age2;
    float gpa2;
    int id2;

    string name3;
    int age3;
    float gpa3;

    cin >> name1;
    cin >> age1;
    cin >> gpa1;

    cin >> name2;
    cin >> age2;
    cin >> gpa2;

    if (gpa1 > gpa2) {
        cout << "Student with higher GPA:" << endl;
        cout << "Name: " << name1 << endl;
        cout << "Age: " << age1 << endl;
        cout << "GPA: " << gpa1 << endl;
    } else {
        cout << "Student with higher GPA:" << endl;
        cout << "Name: " << name2 << endl;
        cout << "Age: " << age2 << endl;
        cout << "GPA: " << gpa2 << endl;
    }

    return 0;
}