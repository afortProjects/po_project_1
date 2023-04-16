#pragma once	
#include "World.h"
class Organism {
protected:
	World& world;
	int posX, posY, age, strength, initiative;
public:
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	virtual ~Organism() = 0;
};