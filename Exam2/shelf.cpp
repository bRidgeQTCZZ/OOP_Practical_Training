#include <iostream>
using namespace std;
#include "shelf.h"

int Shelf::total() {
	return totalNum;
}

void Shelf::bookBeTaken() {
	totalNum--;
}

void Shelf::bookBeBack() {
	totalNum++;
}