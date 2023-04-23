#include "Sheep.h"
Sheep::Sheep(World& world) : Animal(world) {
	this->initiative = 4;
	this->strength = 4;
}
void Sheep::draw() {
	printf("S");
}
Sheep* Sheep::clone() {
	return new Sheep(this->world);
}