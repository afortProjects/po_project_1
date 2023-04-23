#include "Animal.h"
#include "World.h"
#include <iostream>
#include "Human.h"

Animal::Animal(World& world) : world{ world }, Organism(world) {
}

Animal::Animal(World& world, bool isHuman) : world{ world }, Organism(world, isHuman) {

}

Animal* Animal::clone() {
	return new Animal(this->world);
}

void Animal::act() {
	//Move randomly by one field TODO FIX, we are moving on board
	//TODO: Check if positions are in in board
	int tempX = this->posX;
	int tempY = this->posY;
	int tempPosition; // TODO: CHECK

	if (rand()%2) {
		//Move by X
		if (rand()%2) {
			tempX++;
		}
		else {
			tempX--;
		}

	}
	else {
		//Move by Y
		if (rand() % 2) {
			tempY++;
		}
		else {
			tempY--;
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
void Animal::collision() {
	//Check if there is the same species nearby, if yes create new object
	if (typeid(this) == typeid(this->world.board[this->posX][this->posY])) {
		Animal* newAnimal = this->clone();

		//Find place for new animal
		this->world.board[newAnimal->posX][newAnimal->posY] = nullptr;
		if (this->world.board[this->posX + 1][this->posY] == nullptr) {
			newAnimal->posX = this->posX + 1;
			newAnimal->posY = this->posY;
		}
		else if (this->world.board[this->posX - 1][this->posY] == nullptr) {
			newAnimal->posX = this->posX - 1;
			newAnimal->posY = this->posY;
		}
		else if (this->world.board[this->posX][this->posY + 1] == nullptr) {
			newAnimal->posX = this->posX;
			newAnimal->posY = this->posY+1;
		}
		else if (this->world.board[this->posX][this->posY-1] == nullptr) {
			newAnimal->posX = this->posX;
			newAnimal->posY = this->posY-1;
		}
		else if (this->world.board[this->beforeMoveX + 1][this->beforeMoveY] == nullptr) {
			newAnimal->posX = this->beforeMoveX + 1;
			newAnimal->posY = this->beforeMoveY;
		}
		else if (this->world.board[this->beforeMoveX - 1][this->beforeMoveY] == nullptr) {
			newAnimal->posX = this->beforeMoveX-1;
			newAnimal->posY = this->beforeMoveY;
		}
		else if (this->world.board[this->beforeMoveX][this->beforeMoveY+1] == nullptr) {
			newAnimal->posX = this->beforeMoveX;
			newAnimal->posY = this->beforeMoveY+1;
		}
		else if (this->world.board[this->beforeMoveX][this->beforeMoveY-1] == nullptr) {
			newAnimal->posX = this->beforeMoveX;
			newAnimal->posY = this->beforeMoveY-1;
		}

		this->posX = this->beforeMoveX;
		this->posY = this->beforeMoveY;
		this->world.board[newAnimal->posX][newAnimal->posY] = newAnimal;
	}
	else if (this->world.board[this->posX][this->posY]->didReflectAttack(this->strength)) {
		//We have a fight
		Organism* opponent = this->world.board[this->posX][this->posY];
		if (this->strength >= opponent->strength) {
			delete opponent;
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX][this->posY] = this;
		}
		else if (this->strength < opponent->strength) {
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			delete this;
		}
	}
	else {
		this->posX = this->beforeMoveX;
		this->posY = this->beforeMoveY;
	}
}
void Animal::draw() {
	//Draw animal
	printf("A");
}
bool Animal::didReflectAttack(int opponentStrength) {
	return false;
	//Check for attack reflection (turtle)
}
Animal::~Animal() {
	//Destructor
}