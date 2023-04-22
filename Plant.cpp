#include "Plant.h"

Plant::Plant(World& world) : world(world), Organism(world) {

}
void Plant::act() {
	//Chance for breeding
}

void Plant::collision() {
	//Check for collsion
}

void Plant::draw() {
	//Draw plant
}

Plant::~Plant() {

}