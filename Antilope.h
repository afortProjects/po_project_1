#pragma once
#include "Animal.h"
class Antilope : public Animal {
public:
	Antilope(World& world);
	Antilope* clone();
	void draw();
	void act();
	void collision();
};