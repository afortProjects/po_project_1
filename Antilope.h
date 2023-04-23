#pragma once
#include "Animal.h"
class Antilope : public Animal {
	Antilope(World& world);
	void draw();
	void act();
	void collision();
};