#pragma once
#include "Animal.h"
class Turtle : public Animal {
public:
	Turtle(World& world);
	Turtle* clone();
	bool didReflectAttack(int opponentStrength);
	void draw();
	void act();
	void collision();
};