#include <iostream>
using namespace std;

int max(int x, int y)
{
	cout << "int max(int x, int y)" << endl;
	return (x > y) ? x : y;
}

//const int max(int x, int y)
//{
//	cout << "const int max(int x, int y)" << endl;
//	return (x > y) ? x : y;
//}

//int max(const int x, const int y)
//{
//	cout << "int max(const int x, const int y)" << endl;
//	return (x > y) ? x : y;
//}

//int max(int& x, int& y)
//{
//	cout << "int max(int& x, int& y)" << endl;
//	return (x > y) ? x : y;
//}

//int& max(int& x, int& y)
//{
//	cout << "int& max(int& x, int& y)" << endl;
//	return (x > y) ? x : y;
//}

//const int& max(int& x, int& y)
//{
//	cout << "const int& max(int& x, int& y)" << endl;
//	return (x > y) ? x : y;
//}

//int& max(const int& x, const int& y)
//{
//	cout << "int& max(const int& x, const int& y)" << endl;
//	//return (x > y) ? x : y;  ±¨´í
//	int _x = x, _y = y;
//	return (_x > _y) ? _x : _y;
//}

//const int& max(const int& x, const int& y)
//{
//	cout << "const int& max(const int& x, const int& y)" << endl;
//	return (x > y) ? x : y;
//}