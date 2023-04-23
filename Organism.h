#pragma once

#include<iostream>
class World;

class Organism {
protected:
	World& world;
	int posX = 0, posY = 0;
public:
	int initiative = 0	, age = 0, strength = 0;
	Organism(World& world);
	Organism(World& world, bool isHuman);
	Organism* clone();
	bool virtual didReflectAttack(int opponentStrength) = 0;
	int addStrength();
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int getPosX();
	int getPosY();
	~Organism();
};