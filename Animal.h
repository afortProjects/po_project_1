#pragma once
#include "Organism.h"

class Animal : Organism {
	void act() override;
	void collision() override;
	void draw() override;
	bool didReflectAttack();
	~Animal();
};