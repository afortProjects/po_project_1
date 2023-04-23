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
	bool didReflectAttack(int opponentStrength) override;
	void collision() override;
	void draw() override;
	~Plant();
};