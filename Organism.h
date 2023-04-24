#pragma once
#include<iostream>
class World;

class Organism {
protected:
	World& world;
	int posX = 0, posY = 0;
public:
	int initiative = 0	, age = 0, strength = 0, beforeMoveX=0, beforeMoveY=0;
	std::string name = "";

	Organism(World& world);
	Organism(World& world, bool isHuman);

	bool virtual didReflectAttack(int opponentStrength) = 0;
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int virtual addStrength();

	int getPosX();
	int getPosY();
	std::string getName();
	int getStrength();
	~Organism();
};