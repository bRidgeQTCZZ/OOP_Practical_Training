#ifndef BOOK_H
#define BOOK_H

class Book {
public:
	int setName(const char[]);
	string name();
private:
	string theName;
	static const string bookName[10];
	static const char* bookisbn[10];
};

#endif // !BOOK_H
