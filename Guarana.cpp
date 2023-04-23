#include "Guarana.h"

Guarana::Guarana(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;

}

void Guarana::draw() {
	printf("g");
}

int Guarana::addStrength() {
	return 3;
}