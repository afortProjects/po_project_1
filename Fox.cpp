#include "Fox.h"
#include "World.h"
Fox::Fox(World& world) : Animal(world) {
	this->initiative = 7;
	this->strength = 3;
}

void Fox::draw() {
	printf("F");
}

void Fox::act() {
	if (this->world.board[this->posX - 1][this->posY] == nullptr || this->world.board[this->posX - 1][this->posY]->strength < this->strength) {
		this->posX--;
	}
	else if (this->world.board[this->posX +  1][this->posY] == nullptr || this->world.board[this->posX + 1][this->posY]->strength < this->strength) {
		this->posX++;
	}
	else if (this->world.board[this->posX][this->posY-1] == nullptr || this->world.board[this->posX][this->posY-1]->strength < this->strength) {
		this->posY--;
	}
	else if (this->world.board[this->posX][this->posY+1] == nullptr || this->world.board[this->posX][this->posY+1]->strength < this->strength) {
		this->posY++;
	}

	if (this->world.board[this->posX][this->posY] != nullptr) collision();
}

Fox* Fox::clone() {
	return new Fox(this->world);
}