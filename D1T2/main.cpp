#include <iostream>
#include "max.h"
using namespace std;

int main()
{
	int a = 3, b = 4, c = 5, d = 6;
	int retValue01 = max(1, 2);
	int retValue02 = max(a, b);
	//max(a, 3) = 5;
	//max(a, b) = max(c, d);
	cout << "retValue01:" << retValue01 << endl;
	cout << "retValue02:" << retValue02 << endl;
	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;
	cout << "d:" << d << endl;
}