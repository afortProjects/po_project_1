#pragma once
#include<iostream>
class World;

class Organism {
protected:
	World& world;
	int posX = 0, posY = 0;
	int initiative = 0, age = 0, strength = 0, beforeMoveX = 0, beforeMoveY = 0;
	std::string name = "";
public:
	Organism(World& world);
	Organism(World& world, bool isHuman);

	bool virtual didReflectAttack(int opponentStrength) = 0;
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int virtual addStrength();

	void setPosX(int x);
	void setPosY(int y);

	void setBeforeMoveX(int x);
	void setBeforeMoveY(int y);

	void setAge(int age);
	void setStrength(int newStrength);

	int getPosX();
	int getPosY();
	int getBeforeMoveX();
	int getBeforeMoveY();
	int getAge();
	int getStrength();
	int getInitiative();

	std::string getName();

	~Organism();
};