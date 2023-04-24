#include "Grass.h"
#include "World.h"

Grass::Grass(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;
	this->name = "Grass";

}

void Grass::draw() {
	printf("t");
}

Grass* Grass::clone() {
	return new Grass(this->world);
}
