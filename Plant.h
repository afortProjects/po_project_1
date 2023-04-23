#pragma once
#include "Organism.h"
#include "World.h"
class Plant : public Organism {
protected: 
	int initiative = 0;
	World& world;
public:
	Plant(World& world);
	void act() override;
	Plant* clone();
	void collision() override;
	void draw() override;
	~Plant();
};