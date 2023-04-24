#include "Animal.h"
#include "World.h"
#include <iostream>
#include <string>
#include <deque>
#include "Human.h"

Animal::Animal(World& world) : Organism(world) {
}

Animal::Animal(World& world, bool isHuman) : Organism(world, isHuman) {

}

void Animal::act() {
	int tempX = this->posX;
	int tempY = this->posY;
	this->beforeMoveX = tempX;
	this->beforeMoveY = tempY;

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
		this->world.logs.push_front(this->name + " moved to " + std::to_string(this->posX) + ", " + std::to_string(this->posY));

	}


	if (this->world.board[this->posX][this->posY] != nullptr && this->world.board[this->posX][this->posY] != this) collision();

}

void Animal::breed() {
	Animal* newAnimal = this->clone();
	//Find place for new animal
	this->world.board[newAnimal->posX][newAnimal->posY] = nullptr;
	bool foundPlace = false;
	if (this->posX+1 < this->world.a && this->world.board[this->posX + 1][this->posY] == nullptr) {
		newAnimal->posX = this->posX + 1;
		newAnimal->posY = this->posY;
		foundPlace = true;
	}
	else if (this->posX > 0 && this->world.board[this->posX - 1][this->posY] == nullptr) {
		newAnimal->posX = this->posX - 1;
		newAnimal->posY = this->posY;
		foundPlace = true;

	}
	else if (this->posY + 1 < this->world.b && this->world.board[this->posX][this->posY + 1] == nullptr) {
		newAnimal->posX = this->posX;
		newAnimal->posY = this->posY + 1;
		foundPlace = true;

	}
	else if (this->posY > 0 && this->world.board[this->posX][this->posY - 1] == nullptr ) {
		newAnimal->posX = this->posX;
		newAnimal->posY = this->posY - 1;
		foundPlace = true;

	}
	else if (this->beforeMoveX + 1 < this->world.a && this->world.board[this->beforeMoveX + 1][this->beforeMoveY] == nullptr) {
		newAnimal->posX = this->beforeMoveX + 1;
		newAnimal->posY = this->beforeMoveY;
		foundPlace = true;

	}
	else if (this->beforeMoveX > 0 && this->world.board[this->beforeMoveX - 1][this->beforeMoveY] == nullptr) {
		newAnimal->posX = this->beforeMoveX - 1;
		newAnimal->posY = this->beforeMoveY;
		foundPlace = true;

	}
	else if (this->beforeMoveY + 1 < this->world.b && this->world.board[this->beforeMoveX][this->beforeMoveY + 1] == nullptr) {
		newAnimal->posX = this->beforeMoveX;
		newAnimal->posY = this->beforeMoveY + 1;
		foundPlace = true;

	}
	else if (this->beforeMoveY > 0 && this->world.board[this->beforeMoveX][this->beforeMoveY - 1] == nullptr) {
		newAnimal->posX = this->beforeMoveX;
		newAnimal->posY = this->beforeMoveY - 1;
		foundPlace = true;

	}

	this->posX = this->beforeMoveX;
	this->posY = this->beforeMoveY;
	if (foundPlace) {
		this->world.board[newAnimal->posX][newAnimal->posY] = newAnimal;
		this->world.logs.push_front("New " + this->name + " spawned. ");
	}
	else {
		delete newAnimal;
	}

}
Animal* Animal::clone() {
	return nullptr;
}
void Animal::collision() {
	//Check if there is the same species nearby, if yes create new object
	if (this->name ==this->world.board[this->posX][this->posY]->name) {
		this->breed();
	}
	else if (!(this->world.board[this->posX][this->posY]->didReflectAttack(this->strength))) {
		//We have a fight
		Organism* opponent = this->world.board[this->posX][this->posY];

		//Check if guarana
		this->strength += opponent->addStrength();

		if (this->strength >= opponent->strength) {
			if (opponent->getName() == "Human") this->world.endGame();
			//delete opponent;
			//this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX][this->posY] = nullptr;
			this->world.logs.push_front(opponent->getName() + " just died, was killed by " + this->name + ".");

		}

		else if (this->strength < opponent->strength) {
			if (this->getName() == "Human") this->world.endGame();
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			//this = nullptr;
			//delete this
			this->world.logs.push_front(this->name + " just died, was killed by " + opponent->getName() + ".");

		}
	}
	else {
		this->posX = this->beforeMoveX;
		this->posY = this->beforeMoveY;
	}
}

void Animal::draw() {
	printf("A");
}
bool Animal::didReflectAttack(int opponentStrength) {
	//Check for attack reflection (turtle)
	return false;
}
Animal::~Animal() {
	//Destructor
}