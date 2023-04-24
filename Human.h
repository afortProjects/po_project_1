#pragma once
#include "Animal.h"
#include "output.h"

class Human : public Animal {
private:
	bool isAbilityTurnedOn = false;
	int abilityCooldown = 0;
public:
	Human(World& world);
	Human* clone() override;
	void handleInput();
	void act();
	void draw();
	void collision();
	void abillity();
	~Human();
};