#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;
    Pair(T1 a, T2 b) {
        first = a;
        second = b;
    }
    void print() {
        cout << first << " " << second;
    }
};

int main() {
    Pair<int, int> intPair(5, 3);
    Pair<double, double> doublePair(2.5, 4.7);
    Pair<int, double> intDoublePair(7, 3.2);
    Pair<string, string> stringPair("hello", "world");
    
    cout << "Integer pair: ";
    intPair.print();
    cout << endl;
    
    cout << "Double pair: ";
    doublePair.print();
    cout << endl;
    
    cout << "Int-double pair: ";
    intDoublePair.print();
    cout << endl;
    
    cout << "String pair: ";
    stringPair.print();
    cout << endl;
    
    return 0;
}