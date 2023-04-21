#pragma once
#include "Organism.h"

class Animal : public Organism {
public:
	Animal();
	Animal(World* world);
	void act() override;
	void collision() override;
	void draw() override;
	bool didReflectAttack();
	~Animal();
};