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
	num = rand() % 4; //取得0~3的随机数
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

//按X轴旋转90°
void Dice::TurnX() {
	int temp = values[FRONT];
	values[FRONT] = values[TOP];
	values[TOP] = values[BACK];
	values[BACK] = values[BOTTOM];
	values[BOTTOM] = temp;
}

//按Y轴旋转90°
void Dice::TurnY() {
	int temp = values[FRONT];
	values[FRONT] = values[RIGHT];
	values[RIGHT] = values[BACK];
	values[BACK] = values[LEFT];
	values[LEFT] = temp;
}

//按Z轴旋转90°
void Dice::TurnZ() {
	int temp = values[LEFT];
	values[FRONT] = values[TOP];
	values[TOP] = values[BACK];
	values[BACK] = values[BOTTOM];
	values[BOTTOM] = temp;
}