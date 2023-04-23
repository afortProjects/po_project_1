#pragma once
#include "Animal.h"
class Sheep : public Animal {
public:
	Sheep(World& world);
	void draw();
	Sheep* clone();
};