#include "Blueberry.h"

Blueberry::Blueberry(World& world) : Plant(world) {
	this->strength = 99;
	this->initiative = 0;
	this->name = "Blueberry";

}

void Blueberry::draw() {
	printf("b");
}

Blueberry* Blueberry::clone() {
	return new Blueberry(this->world);
}