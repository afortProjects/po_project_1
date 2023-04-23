#include "Dandelion.h"

Dandelion::Dandelion(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;
}

void Dandelion::draw() {
	printf("d");
}

void Dandelion::act() {
	for (int i = 0; i < 3; i++) {
		Plant::act();
	}
}