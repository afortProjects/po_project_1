#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal(World& world);
	Animal(World& world, bool isHuman);

	virtual Animal* clone();

	void virtual act() override;
	void virtual collision() override;
	void virtual draw() override;
	bool virtual didReflectAttack(int opponentStrength) override;

	void breed();
	~Animal();
};