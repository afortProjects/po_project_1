#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	int beforeMoveX, beforeMoveY;
	bool isAnimal = true;
	World& world;
	Animal(World& world);
	Animal(World& world, bool isHuman);
	Animal* clone();
	void act() override;
	void collision() override;
	void draw() override;
	bool didReflectAttack(int opponentStrength);
	~Animal();
};