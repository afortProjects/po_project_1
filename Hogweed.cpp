#include "World.h"
#include "Hogweed.h"
#include "Animal.h"
Hogweed::Hogweed(World& world) : Plant(world) {
	this->strength = 10;
}

void Hogweed::draw() {
	printf("h");
}

void Hogweed::act() {
	//Killing all animals nearby
	if (dynamic_cast<Animal*>(this->world.board[this->posX - 1][this->posY]) == nullptr) {
		Organism* animalToDelete = this->world.board[this->posX - 1][this->posY];
		this->world.board[this->posX - 1][this->posY] = nullptr;
		delete animalToDelete;
	}
	if (dynamic_cast<Animal*>(this->world.board[this->posX + 1][this->posY]) == nullptr) {
		Organism* animalToDelete = this->world.board[this->posX + 1][this->posY];
		this->world.board[this->posX + 1][this->posY] = nullptr;
		delete animalToDelete;
	}
	if (dynamic_cast<Animal*>(this->world.board[this->posX][this->posY -1]) == nullptr) {
		Organism* animalToDelete = this->world.board[this->posX][this->posY -1];
		this->world.board[this->posX][this->posY-1] = nullptr;
		delete animalToDelete;
	}
	if (dynamic_cast<Animal*>(this->world.board[this->posX][this->posY + 1]) == nullptr) {
		Organism* animalToDelete = this->world.board[this->posX][this->posY + 1];
		this->world.board[this->posX][this->posY + 1] = nullptr;
		delete animalToDelete;
	}
	Plant::act();
}