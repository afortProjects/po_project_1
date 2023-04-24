#pragma once
#include "Plant.h"

class Hogweed : public Plant {
public:
	Hogweed(World& world);
	void act();
	void draw();
	Hogweed* clone();
};