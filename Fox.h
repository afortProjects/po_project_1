#pragma once
#include "Animal.h"
class Fox : public Animal {
public:
	Fox(World& world);
	void draw();
	void act();
	Fox* clone();
};