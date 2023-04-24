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
	if (this->posX > 0 && (this->world.board[this->posX - 1][this->posY] == nullptr || this->world.board[this->posX - 1][this->posY]->strength < this->strength)) {
		this->posX--;
	}
	else if (this->posX + 1 < this->world.a && (this->world.board[this->posX + 1][this->posY] == nullptr || this->world.board[this->posX + 1][this->posY]->strength < this->strength)) {
		this->posX++;
	}
	else if (this->posY > 0 && (this->world.board[this->posX][this->posY - 1] == nullptr || this->world.board[this->posX][this->posY - 1]->strength < this->strength)) {
		this->posY--;
	}
	else if (this->posY + 1 < this->world.b && (this->world.board[this->posX][this->posY + 1] == nullptr || this->world.board[this->posX][this->posY + 1]->strength < this->strength)) {
		this->posY++;
	}

	if (this->world.board[this->posX][this->posY] != nullptr) collision();
}

Fox* Fox::clone() {
	return new Fox(this->world);
}