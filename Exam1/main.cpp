#include <iostream>
using namespace std;

class Sensor {
public:
    Sensor(const string& yourName) : name(yourName) {} //问题1
public:
    float readValue() const {
        unsigned int val = ((mLow16 << 16) | mHigh16);
        return *((float*)(&val));
    }
    void  setValue(float val) {
        unsigned int  binary32 = *(unsigned int*)(&val);
        mLow16 = ((binary32 >> 16) & 0xFFFF);
        mHigh16 = (binary32 & 0xFFFF);
    }
    const string& studentName() const { return name; } //问题2
    void setHigh(int v) { mHigh16 = v & 0xFFFF; }
    void setLow(int v) { mLow16 = v & 0xFFFF; }
    unsigned  int high() const { return mHigh16; }
    unsigned  int low() const { return mLow16; }
private:
    string  name;
    unsigned int mHigh16 = 0;
    unsigned int mLow16 = 0;
};

int main()
{
    Sensor s("黄一桐");
    cout << "姓名：" << s.studentName() << endl;
    float n = 8.55;
    for (int i = 0; i < 10; i++)
    {
        s.setValue(n * i);
        cout << "i=" << i;
        cout << "\tHigh=" << hex << s.high();
        cout << "\tLow=" << hex << s.low();
        cout << "\tfloat=" << s.readValue() << endl;
    }
}
