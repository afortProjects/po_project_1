#include "Plant.h"

Plant::Plant(World& world) : Organism(world) {
	this->initiative = 0;
}
bool Plant::didReflectAttack(int opponentStrength) {
	return false;
}

void Plant::act() {
	//Chance for breeding
	if (rand() % 2 && rand() % 2) {
		int newPlantX, newPlantY;
		bool foundNewPlace = false;
		this->findPlaceForChild(foundNewPlace, newPlantX, newPlantY);

		if (foundNewPlace) {
			Plant* newPlant = this->clone();
			this->world.board[newPlant->getPosX()][newPlant->getPosY()] = nullptr;
			newPlant->posX = newPlantX;
			newPlant->posY = newPlantY;
			this->world.board[newPlantX][newPlantY] = newPlant;
		}
		this->world.logs.push_front(this->getName() + " was created.");

	}
}

void Plant::findPlaceForChild(bool& foundNewPlace, int& newPlantX, int& newPlantY) {
	if (this->posX >= 1 && this->world.board[this->posX - 1][this->posY] == nullptr) {
		newPlantX = this->posX - 1;
		newPlantY = this->posY;
		foundNewPlace = true;
	}
	else if (this->posX + 1 < this->world.a && this->world.board[this->posX + 1][this->posY] == nullptr) {
		newPlantX = this->posX + 1;
		newPlantY = this->posY;
		foundNewPlace = true;

	}
	else if (this->posY >= 1 && this->world.board[this->posX][this->posY - 1] == nullptr) {
		newPlantX = this->posX;
		newPlantY = this->posY - 1;
		foundNewPlace = true;

	}
	else if (this->posY + 1 < this->world.b && this->world.board[this->posX][this->posY + 1] == nullptr) {
		newPlantX = this->posX;
		newPlantY = this->posY + 1;
		foundNewPlace = true;
	}
}

void Plant::collision() {}

void Plant::draw() {
	printf("P");
}

Plant::~Plant() {

}