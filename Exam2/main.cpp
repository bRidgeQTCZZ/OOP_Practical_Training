#include <iostream>
#include <string>
using namespace std;
#include "shelf.h"
#include "student.h"
#include "book.h"

int main() {
	Shelf* shelf = new Shelf;
	cout << "书架剩余图书数量=" << shelf->total() << endl;

	Student s1("999999", "张三");
	Student s2("21210413", "黄一桐");

	//借书
	Book* book1 = s1.takeBook(*shelf, "ISBN-100");
	if (book1)
		cout << s1.name() << "借走一本书，书名为：" << book1->name() << endl;
	else
		cout << s1.name() << "所借图书不存在！" << endl;

	Book* book2 = s2.takeBook(*shelf, "ISBN-102");
	if (book2)
		cout << s2.name() << "借走一本书，书名为：" << book2->name() << endl;
	else
		cout << s2.name() << "所借图书不存在！" << endl;

	cout << "书架剩余图书数量=" << shelf->total() << endl;

	//还书
	if (book1)
		s1.backBook(*shelf, *book1);
	if (book2)
		s2.backBook(*shelf, *book2);

	cout << "书架剩余图书数量=" << shelf->total() << endl;
	
	delete shelf;
}