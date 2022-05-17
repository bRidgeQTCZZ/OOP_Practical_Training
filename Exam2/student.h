#ifndef STUDENT_H
#define STUDENT_H

class Book;
class Shelf;
class Student {
public:
	Student(string num, string name) : stuNum(num), stuName(name) {}
	Book* takeBook(Shelf&, const char[]);
	void backBook(Shelf&, Book&);
	string name();
private:
	string stuNum;
	string stuName;
};

#endif // !STUDENT_H
