#include <iostream>
#include <string>
using namespace std;

// تابع برای دریافت اطلاعات یک دانشجو
void getStudentInfo(string &name, int &age, float &gpa) {
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student GPA: ";
    cin >> gpa;
    cin.ignore(); // برای پاک کردن بافر ورودی
}

// تابع برای چاپ اطلاعات دانشجو
void printStudentInfo(string name, int age, float gpa) {
    cout << "Student with higher GPA:" << endl;
    cout << "Name: " << name << endl;
    cout << "Age: " << age << endl;
    cout << "GPA: " << gpa << endl;
}

int main() {
    // متغیرهای دانشجوی اول
    string name1;
    int age1;
    float gpa1;

    // متغیرهای دانشجوی دوم
    string name2;
    int age2;
    float gpa2;

    // دریافت اطلاعات دانشجوی اول
    cout << "Enter information for first student:" << endl;
    getStudentInfo(name1, age1, gpa1);

    // دریافت اطلاعات دانشجوی دوم
    cout << "\nEnter information for second student:" << endl;
    getStudentInfo(name2, age2, gpa2);

    // مقایسه معدل‌ها و چاپ اطلاعات دانشجوی با معدل بالاتر
    if (gpa1 > gpa2) {
        printStudentInfo(name1, age1, gpa1);
    } else {
        printStudentInfo(name2, age2, gpa2);
    }

    return 0;
}