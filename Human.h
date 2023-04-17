#pragma once
#include "Animal.h"
class Human : public Animal {
	Human();
	void act();
	void collision();
	~Human();
};