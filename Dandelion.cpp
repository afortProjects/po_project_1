#include "Dandelion.h"

Dandelion::Dandelion(World& world) : Plant(world) {
	this->strength = 0;
	this->initiative = 0;
	this->name = "Dandelion";
}

void Dandelion::draw() {
	printf("d");
}

Dandelion* Dandelion::clone() {
	return new Dandelion(this->world);
}

void Dandelion::act() {
	for (int i = 0; i < 3; i++) {
		if (rand() % 2 && rand() % 2) {
			int newPlantX, newPlantY;
			bool foundNewPlace = false;
			this->findPlaceForChild(foundNewPlace, newPlantX, newPlantY);

			if (foundNewPlace) {
				Dandelion* newDandelion = this->clone();
				this->world.board[newDandelion->getPosX()][newDandelion->getPosY()] = nullptr;
				newDandelion->posX = newPlantX;
				newDandelion->posY = newPlantY;
				this->world.board[newPlantX][newPlantY] = newDandelion;
				this->world.logs.push_front(this->getName() + " was created.");

				break;
			}
		}
	}
}