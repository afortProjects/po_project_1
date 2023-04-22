#pragma once
#include "Animal.h"
#include "output.h"

class Human : public Animal {
public:
	int posX=1, posY = 1;
	bool isAnimal = false;
	World& world;
	Human(World& world);
	void act();
	void collision();
	~Human();
};