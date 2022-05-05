#include <iostream>
using namespace std;

class A {
public:
    /*void Display() const {
        cout << "The argument is NULL" << endl;
    }*/
    inline void Display() const;

    void Display(const char* str) const {
        cout << "The argument is " << str << endl;
    }
    void OtherFunc() {
    }
};

void A::Display() const {
    cout << "The argument is NULL" << endl;
}