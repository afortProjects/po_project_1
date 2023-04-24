#pragma once
#include "Plant.h"
class Guarana : public Plant {
public:
	Guarana(World& world);
	int addStrength();
	void draw();
	Guarana* clone();
};