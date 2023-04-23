#pragma once
#include "Plant.h"
class Dandelion : public Plant {
	Dandelion(World& world);
	void draw();
	void act();
};