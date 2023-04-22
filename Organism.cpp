#include "Organism.h"

Organism::Organism(World& world) : world(world){}
Organism::~Organism() {}

int Organism::getPosX() {
	return this->posX;
}

int Organism::getPosY() {
	return this->posY;
}
//Consider initiative and age
bool Organism::operator >(const Organism* object)
{
	if (this->initiative == object->initiative) return (this->age > object->age);
	return (this->initiative > object->initiative);
}