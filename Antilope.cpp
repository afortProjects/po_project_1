#include "Antilope.h"
#include "World.h"
Antilope::Antilope(World& world) : Animal(world) {
	this->strength = 4;
	this->initiative = 4;
}

void Antilope::draw() {
	printf("A");
}

void Antilope::act() {
	int tempX = this->posX;
	int tempY = this->posY;

	if (rand() % 2) {
		//Move by X
		if (rand() % 2) {
			tempX+=2;	
		}
		else {
			tempX-=2;
		}

	}
	else {
		//Move by Y
		if (rand() % 2) {
			tempY+=2;
		}
		else {
			tempY-=2;
		}
	}
	if (tempX >= 0 && tempX < this->world.a && tempY >= 0 && tempY < this->world.b) {
		this->posX = tempX;
		this->posY = tempY;
	}
	this->beforeMoveX = tempX;
	this->beforeMoveY = tempY;

	if (this->world.board[this->posX][this->posY] != nullptr) collision();

}

void Antilope::collision() {
	if (rand() % 2) {
		//Antilope runs from fight
		if (this->world.board[this->posX + 1][this->posY] == nullptr) {
			this->world.board[this->posX + 1][this->posY] = this;
			this->posX++;
		} else if (this->world.board[this->posX - 1][this->posY] == nullptr) {
			this->world.board[this->posX - 1][this->posY] = this;
			this->posX--;
		}
		else if (this->world.board[this->posX][this->posY+1] == nullptr) {
			this->world.board[this->posX][this->posY+1] = this;
			this->posY++;
		}
		else if (this->world.board[this->posX][this->posY-1] == nullptr) {
			this->world.board[this->posX][this->posY-1] = this;
			this->posY--;
		}
		else {
			//If there is no available place, there is fight
			Animal::collision();
		}
	}
	else {
		Animal::collision();
	}
}