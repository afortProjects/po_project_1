#pragma once
#include "Plant.h"
class Guarana : public Plant {
	Guarana(World& world);
	int addStrength();
	void draw();
};