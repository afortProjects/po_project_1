#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	bool isAnimal = true;
	World& world;
	Animal(World& world);
	Animal(World& world, bool isHuman);
	void act() override;
	void collision() override;
	void draw() override;
	bool didReflectAttack();
	~Animal();
};