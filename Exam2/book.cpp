#include <iostream>
using namespace std;
#include "book.h"

const string Book::bookName[10] = {
	"书名01",
	"书名02",
	"书名03",
	"书名04",
	"书名05",
	"书名06",
	"书名07",
	"书名08",
	"书名09",
	"书名10"
};

const char* Book::bookisbn[10] = {
	"ISBN-101",
	"ISBN-102",
	"ISBN-103",
	"ISBN-104",
	"ISBN-105",
	"ISBN-106",
	"ISBN-107",
	"ISBN-108",
	"ISBN-109",
	"ISBN-110"
};

int Book::setName(const char isbn[]) {
	for (int i = 0; i < 10; i++)
		if (!strcmp(isbn, bookisbn[i]))
		{
			theName = bookName[i];
			return 1;
		}
	return 0;
}

string Book::name() {
	return theName;
}