#include "Grass.h"
#include "World.h"

Grass::Grass(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;

}

void Grass::draw() {
	printf("t");
}
