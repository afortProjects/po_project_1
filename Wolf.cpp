#include "Wolf.h"

Wolf::Wolf(World& world) : Animal(world) {
	this->initiative = 5; 
	this->strength = 9;
}

void Wolf::draw() {
	printf("W");
}

Wolf* Wolf::clone() {
	return new Wolf(this->world);
}