#include "Organism.h"

Organism::Organism() {}
Organism::~Organism() {}

int Organism::getPosX() {
	return this->posX;
}

int Organism::getPosY() {
	return this->posY;
}

bool Organism::operator >(const Organism* object)
{
	return (this->initiative> object->initiative);
}