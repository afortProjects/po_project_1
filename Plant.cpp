#include "Plant.h"

Plant::Plant(World& world) : world(world), Organism(world) {

}
Plant* Plant::clone() {
	return new Plant(this->world);
}
bool Plant::didReflectAttack(int opponentStrength) {
	return false;
}
void Plant::act() {
	//Chance for breeding
	if (rand() % 2 && rand() % 2) {
		int newPlantX, newPlantY;
		bool foundNewPlace = false;
		if (this->posX >= 1 && this->world.board[this->posX - 1][this->posY] == nullptr) {
			newPlantX = this->posX - 1;
			newPlantY = this->posY;
			foundNewPlace = true;
		}
		else if (this->posX + 1< this->world.a && this->world.board[this->posX + 1][this->posY] == nullptr) {
			newPlantX = this->posX + 1; 
			newPlantY = this->posY;
			foundNewPlace = true;

		}
		else if (this->posY >= 1 && this->world.board[this->posX][this->posY - 1] == nullptr) {
			newPlantX = this->posX;
			newPlantY = this->posY-1;
			foundNewPlace = true;

		}
		else if (this->posY + 1 < this->world.b && this->world.board[this->posX][this->posY + 1] == nullptr) {
			newPlantX = this->posX;
			newPlantY = this->posY+1;
			foundNewPlace = true;

		}

		if (foundNewPlace) {
			Plant* newPlant = new Plant(this->world);
			newPlant->posX = newPlantX;
			newPlant->posY = newPlantY;
			this->world.board[newPlantX][newPlantY] = newPlant;
		}
	}
}

void Plant::collision() {
	//Check for collision
}

void Plant::draw() {
	//Draw plant
	printf("P");
}

Plant::~Plant() {

}