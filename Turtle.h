#pragma once
#include "Animal.h"
class Turtle : public Animal {
	Turtle(World& world);
	Turtle* clone();
	bool didReflectAttack(int opponentStrength);
	void draw();
	void act();
	void collision();
};