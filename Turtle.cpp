#include "Turtle.h"
#include "World.h"
Turtle::Turtle(World& world) : Animal(world) {
	this->initiative = 1;
	this->strength = 2;
}

void Turtle::draw() {
	printf("T");
}

void Turtle::act() {
	if (rand() % 4 == 3) Animal::act();
}

void Turtle::collision() {

}
Turtle* Turtle::clone() {
	return new Turtle(this->world);
}
bool Turtle::didReflectAttack(int opponentStrength) {
	if (opponentStrength < 5) {
		return true;
	}
	else {
		return false;
	}
}