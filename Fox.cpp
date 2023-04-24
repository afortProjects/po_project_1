#include "Fox.h"
#include "World.h"
Fox::Fox(World& world) : Animal(world) {
	this->initiative = 7;
	this->strength = 3;
	this->name = "Fox";

}

void Fox::draw() {
	printf("F");
}

void Fox::act() {
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	if (this->posX > 0 && (board[this->posX - 1][this->posY] == nullptr || board[this->posX - 1][this->posY]->getStrength() < this->strength)) {
		this->posX--;
	}
	else if (this->posX + 1 < this->world.getA() && (board[this->posX + 1][this->posY] == nullptr || board[this->posX + 1][this->posY]->getStrength() < this->strength)) {
		this->posX++;
	}
	else if (this->posY > 0 && (board[this->posX][this->posY - 1] == nullptr || board[this->posX][this->posY - 1]->getStrength() < this->strength)) {
		this->posY--;
	}
	else if (this->posY + 1 < this->world.getB() && (board[this->posX][this->posY + 1] == nullptr || board[this->posX][this->posY + 1]->getStrength() < this->strength)) {
		this->posY++;
	}

	if (board[this->posX][this->posY] != nullptr) collision();
}

Fox* Fox::clone() {
	return new Fox(this->world);
}