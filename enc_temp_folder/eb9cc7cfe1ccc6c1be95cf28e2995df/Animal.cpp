#include "Animal.h"
#include "World.h"
#include <iostream>
#include "Human.h"
//Animal::Animal() {};

Animal::Animal(World& world, bool isHuman) : world{ world }, Organism(world, isHuman) {

}

Animal::Animal(World& world) : world{ world }, Organism(world) {

}
void Animal::act() {
	//Move randomly by one field TODO FIX, we are moving on board
	//TODO: Check if positions are in in board
	int tempX = this->posX;
	int tempY = this->posY;
	int tempPosition; // TODO: CHECK

	if (rand()%2) {
		//Move by X
		if (rand()%2) {
			tempX++;
		}
		else {
			tempX--;
		}

	}
	else {
		//Move by Y
		if (rand() % 2) {
			tempY++;
		}
		else {
			tempY--;
		}
	}
	if (tempX >= 0 && tempX < this->world.a && tempY >= 0 && tempY < this->world.b) {
		this->posX = tempX;
		this->posY = tempY;
	}
}
void Animal::collision() {
	//Check if there is the same species nearby, if yes create new object

}
void Animal::draw() {
	//Draw animal
	printf("A");
}
bool Animal::didReflectAttack() {
	return true;
	//Check for attack reflection (turtle)
}
Animal::~Animal() {
	//Destructor
}