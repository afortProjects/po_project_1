#pragma once
#include "Animal.h"
#include "output.h"

class Human : public Animal {
public:
	Human(World& world);
	Human* clone() override;
	void act();
	void draw();
	void collision();
	~Human();
};