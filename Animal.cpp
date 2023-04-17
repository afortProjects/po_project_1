#include "Animal.h"
#include <iostream>
Animal::Animal() {
	//Constructor
}
void Animal::act() {
	//Move randomly by one field
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