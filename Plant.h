#pragma once
#include "Organism.h"
#include "World.h"
class Plant : public Organism {
public:
	Plant(World& world);

	virtual Plant* clone() = 0;

	void virtual act() override;
	bool virtual didReflectAttack(int opponentStrength) override;
	void virtual collision() override;
	void virtual draw() override;

	void findPlaceForChild(bool& foundNewPlace, int& newPlantX, int& newPlantY);
	~Plant();
};