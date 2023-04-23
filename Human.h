#pragma once
#include "Animal.h"
#include "output.h"

class Human : public Animal {
public:
	int posX=1, posY = 1, initiative = 4, strength = 5;
	bool isAnimal = false;
	World& world;
	Human(World& world);
	void act();
	void draw();
	void collision();
	~Human();
};