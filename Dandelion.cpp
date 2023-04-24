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
	std::vector<std::vector<Organism*>> board = this->world.getBoard();
	 

	for (int i = 0; i < 3; i++) {
		if (rand() % 2 && rand() % 2) {
			int newPlantX, newPlantY;
			bool foundNewPlace = false;
			this->findPlaceForChild(foundNewPlace, newPlantX, newPlantY);

			if (foundNewPlace) {
				Dandelion* newDandelion = this->clone();
				board[newDandelion->getPosX()][newDandelion->getPosY()] = nullptr;
				newDandelion->posX = newPlantX;
				newDandelion->posY = newPlantY;
				board[newPlantX][newPlantY] = newDandelion;
				this->world.addLog(this->getName() + " was created.");
				break;
			}
			else if (!(this->world.checkIfThereIsPlaceAvailable())) {
				this->world.endGame("There is no available space. ");
			}
		}
	}
	this->world.setBoard(board);


}