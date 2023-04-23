#pragma once
#include "Animal.h"
class Fox : public Animal {
	Fox(World& world);
	void draw();
	void act();
	Fox* clone();
};