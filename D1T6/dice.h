#ifndef DICE_H
#define DICE_H

class Dice {
public:
	static const enum SIDE { FRONT = 0, LEFT, TOP, RIGHT, BOTTOM, BACK };
	static const char* Names[];
public:
	Dice();
	int Cast();
	int FaceValue(SIDE side) const;
private:
	void Turn();
	void TurnX();
	void TurnY();
	void TurnZ();
private:
	int values[6];
};

#endif