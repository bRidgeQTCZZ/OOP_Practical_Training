#include <iostream>
using namespace std;
#include "student.h"
#include "shelf.h"
#include "book.h"

Book* Student::takeBook(Shelf& shelf, const char isbn[]) {
	Book* temp = new(Book);
	if (!temp->setName(isbn))
		return NULL;
	else
		shelf.bookBeTaken();
	return temp;
}

void Student::backBook(Shelf& shelf, Book& book) {
	shelf.bookBeBack();
}

string Student::name() {
	return stuName;
}