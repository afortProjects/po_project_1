#include "Guarana.h"

Guarana::Guarana(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;
	this->name = "Guarana";
}

void Guarana::draw() {
	printf("g");
}

int Guarana::addStrength() {
	this->world.addLog(this->getName() + " just added strength.");
	return 3;
}

Guarana* Guarana::clone() {
	return new Guarana(this->world);
}