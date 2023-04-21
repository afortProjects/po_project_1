#include "Animal.h"
#include "World.h"
#include <iostream>
Animal::Animal() {};

Animal::Animal(World* world) {
	//Constructor
	this->world = world;
	this->posX = int(rand() % this->world->a + 1);
	this->posY = int(rand() % this->world->b + 1);
	this->positionInBoard = this->posX * this->world->a + this->posY; // TODO: CHECK
	this->world->board[this->positionInBoard] = this;
}
void Animal::act() {
	//Move randomly by one field TODO FIX, we are moving on board
	//TODO: Check if positions are in in board
	int tempX = this->posX;
	int tempY = this->posY;
	int tempPosition; // TODO: CHECK

	if ((round((double)rand() / (RAND_MAX)))) {
		//Move by X
		if (((double)rand() / (RAND_MAX))) {
			tempX++;
		}
		else {
			tempX--;
		}

	}
	else {
		//Move by Y
		if ((round((double)rand() / (RAND_MAX)))) {
			tempY++;
		}
		else {
			tempY--;
		}
	}
	if (tempX >= 0 && tempX < this->world->a && tempY >= 0 && tempY < this->world->b) {
		this->world->board[this->positionInBoard] = nullptr;
		tempPosition = tempX * this->world->a + tempY; // TODO: FIX 

		this->world->board[tempPosition] = this;

		this->positionInBoard = tempPosition;
		this->posX = tempX;
		this->posY = tempY;
	}
}
void Animal::collision() {
	//Check if there is the same species nearby, if yes create new object

}
void Animal::draw() {
	//Draw animal
}
bool Animal::didReflectAttack() {
	return true;
	//Check for attack reflection (turtle)
}
Animal::~Animal() {
	//Destructor
}