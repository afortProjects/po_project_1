#pragma once
#include "Plant.h"
class Dandelion : public Plant {
public:
	Dandelion(World& world);
	void draw();
	void act();
	Dandelion* clone();
};