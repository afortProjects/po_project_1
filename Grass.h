#pragma once
#include "Plant.h"
class Grass : public Plant {
public:
	Grass(World& world);
	void draw();
	Grass* clone();
};