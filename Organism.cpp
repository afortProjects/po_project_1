#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism(World& world) : world(world) {
	//this->initiative = (1+ (rand() % 10));
	//Constructor
	this->posX = floor(rand() % world.a);
	this->posY = floor(rand() % world.b);

	//Check if place is not occupied
	while (this->world.board[this->posX][this->posY] != nullptr) {
		this->posX = floor(rand() % this->world.a);
		this->posY = floor(rand() % this->world.b);
	}

	this->world.board[this->posX][this->posY] = this;
}

Organism::Organism(World& world, bool isHuman) : world(world) {
	//this->initiative = (1+ (rand() % 10));
}

Organism* clone() {
	return nullptr;
}

int Organism::getPosX() {
	return this->posX;
}

int Organism::getPosY() {
	return this->posY;
}

Organism::~Organism() {

}