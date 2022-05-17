#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "dice.h"

const char* Dice::Names[] = { "FRONT", "LEFT", "TOP", "RIGHT", "BOTTOM", "BACK" };

Dice::Dice() {
	values[FRONT] = 1;
	values[TOP] = 1;
	values[RIGHT] = 1;
	values[LEFT] = 1;
	values[BOTTOM] = 1;
	values[BACK] = 1;

	srand(time(0));
}

int Dice::Cast() {
	Turn();
	return FaceValue(FRONT);
}

void Dice::Turn() {
	int num;
	num = rand() % 4; //ȡ��0~3�������
	for (int i = 0; i < num; i++)
		TurnX();
	num = rand() % 4;
	for (int i = 0; i < num; i++)
		TurnY();
	num = rand() % 4;
	for (int i = 0; i < num; i++)
		TurnZ();
}

int Dice::FaceValue(SIDE side) const {
	return values[side];
}

//��X����ת90��
void Dice::TurnX() {
	int temp = values[FRONT];
	values[FRONT] = values[TOP];
	values[TOP] = values[BACK];
	values[BACK] = values[BOTTOM];
	values[BOTTOM] = temp;
}

//��Y����ת90��
void Dice::TurnY() {
	int temp = values[FRONT];
	values[FRONT] = values[RIGHT];
	values[RIGHT] = values[BACK];
	values[BACK] = values[LEFT];
	values[LEFT] = temp;
}

//��Z����ת90��
void Dice::TurnZ() {
	int temp = values[LEFT];
	values[FRONT] = values[TOP];
	values[TOP] = values[BACK];
	values[BACK] = values[BOTTOM];
	values[BOTTOM] = temp;
}