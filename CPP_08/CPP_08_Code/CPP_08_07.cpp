#include <iostream>
using namespace std;
class Distance {
private:
    int meter;
    // friend function

    friend int addFive(Distance d) {

    //accessing private members from the friend function
    d.meter += 5;
    return d.meter;
}

public:
    Distance() : meter(0) {}
        
};

// friend function definition


int main() {
    Distance D;
    cout << "Distance: " << addFive(D);
    return 0;
}
