#include "Organism.h"
#include <iostream>

Organism::Organism(World& world) : world(world) {
	//this->initiative = (1+ (rand() % 10));
}

int Organism::getPosX() {
	return this->posX;
}

int Organism::getPosY() {
	return this->posY;
}

Organism::~Organism() {

}