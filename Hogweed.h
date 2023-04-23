#pragma once
#include "Plant.h"

class Hogweed : public Plant {
	Hogweed(World& world);
	void act();
	void draw();
};