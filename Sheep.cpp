#include "Sheep.h"
Sheep::Sheep(World& world) : Animal(world) {
	this->initiative = 4;
	this->strength = 4;
	this->name = "Sheep";

}
void Sheep::draw() {
	printf("S");
}

Sheep* Sheep::clone() {
	return new Sheep(this->world);
}