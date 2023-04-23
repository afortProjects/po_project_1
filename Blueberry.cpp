#include "Blueberry.h"

Blueberry::Blueberry(World& world) : Plant(world) {
	this->strength = 99;
}

void Blueberry::draw() {
	printf("b");
}