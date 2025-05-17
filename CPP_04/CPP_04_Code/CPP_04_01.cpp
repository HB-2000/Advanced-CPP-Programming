#include <iostream>
#include <string>
using namespace std;

// تعریف کلاس student
class student {
public:
    string name;
    float grade;
    static int studentCount; // متغیر استاتیک برای شمارش دانشجویان
    static string lastAddedName; // متغیر استاتیک برای نام آخرین دانشجو
    static const float MAX_GRADE; // متغیر ثابت استاتیک برای حداکثر معدل

    student(string n, float g) {
        name = n;
        if (g > MAX_GRADE) {
            grade = 0.0; // اگر معدل بیشتر از حداکثر باشد، 0 تنظیم می‌شود
        } else {
            grade = g;
        }
        studentCount++;
        lastAddedName = n;
    }

    static void displayCount() { // تابع استاتیک برای نمایش تعداد و اطلاعات
        cout << "Total students: " << studentCount << endl;
        cout << "Last added student: " << lastAddedName << endl;
        cout << "Maximum possible grade: " << MAX_GRADE << endl;
    }
};

// مقداردهی اولیه متغیرهای استاتیک
int student::studentCount = 0;
string student::lastAddedName = "";
const float student::MAX_GRADE = 20.0;

int main() {
    student s1("Ali", 18.5);
    student s2("Reza", 21.0); // معدل بیشتر از MAX_GRADE است، پس 0 می‌شود
    student s3("Sara", 17.8);

    student::displayCount(); // نمایش تعداد، نام آخرین دانشجو و حداکثر معدل

    return 0;
}