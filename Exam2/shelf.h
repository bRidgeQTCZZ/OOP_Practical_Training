#ifndef SHELF_H
#define SHELF_H

class Shelf {
public:
	int total();
	void bookBeTaken();
	void bookBeBack();
private:
	int totalNum = 10;
};

#endif // !SHELF_H
