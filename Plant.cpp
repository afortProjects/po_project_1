#include "Plant.h"

Plant::Plant(World& world) : Organism(world) {
	this->initiative = 0;
}
bool Plant::didReflectAttack(int opponentStrength) {
	return false;
}

void Plant::act() {
	std::vector<std::vector<Organism*>> board = this->world.getBoard();
	//Chance for breeding
	if (rand() % 2 && rand() % 2) {
		int newPlantX, newPlantY;
		bool foundNewPlace = false;
		this->findPlaceForChild(foundNewPlace, newPlantX, newPlantY);

		if (foundNewPlace) {
			Plant* newPlant = this->clone();
			board[newPlant->getPosX()][newPlant->getPosY()] = nullptr;
			newPlant->posX = newPlantX;
			newPlant->posY = newPlantY;
			board[newPlantX][newPlantY] = newPlant;
		}
		this->world.addLog(this->getName() + " was created.");

	}

	this->world.setBoard(board);

}

void Plant::findPlaceForChild(bool& foundNewPlace, int& newPlantX, int& newPlantY) {
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	if (this->posX >= 1 && board[this->posX - 1][this->posY] == nullptr) {
		newPlantX = this->posX - 1;
		newPlantY = this->posY;
		foundNewPlace = true;
	}
	else if (this->posX + 1 < this->world.getA() && board[this->posX + 1][this->posY] == nullptr) {
		newPlantX = this->posX + 1;
		newPlantY = this->posY;
		foundNewPlace = true;

	}
	else if (this->posY >= 1 && board[this->posX][this->posY - 1] == nullptr) {
		newPlantX = this->posX;
		newPlantY = this->posY - 1;
		foundNewPlace = true;

	}
	else if (this->posY + 1 < this->world.getB() && board[this->posX][this->posY + 1] == nullptr) {
		newPlantX = this->posX;
		newPlantY = this->posY + 1;
		foundNewPlace = true;
	}

	this->world.setBoard(board);

}

void Plant::collision() {}

void Plant::draw() {
	printf("P");
}

Plant::~Plant() {

}