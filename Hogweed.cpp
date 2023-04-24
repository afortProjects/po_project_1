#include "World.h"
#include "Hogweed.h"
#include "Animal.h"
Hogweed::Hogweed(World& world) : Plant(world) {
	this->strength = 10;
	this->initiative = 0;
	this->name = "Hogweed";
}

Hogweed* Hogweed::clone() {
	return new Hogweed(this->world);
}

void Hogweed::draw() {
	printf("h");
}

void Hogweed::act() {
	//Killing all animals nearby
	if (this->posX > 0 && dynamic_cast<Animal*>(this->world.board[this->posX - 1][this->posY]) != nullptr) {
		Organism* animalToDelete = this->world.board[this->posX - 1][this->posY];
		this->world.board[this->posX - 1][this->posY] = nullptr;
		if(animalToDelete != nullptr)
			this->world.logs.push_front(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();


	}
	if (this->posX + 1 < this->world.a && dynamic_cast<Animal*>(this->world.board[this->posX + 1][this->posY]) != nullptr) {
		Organism* animalToDelete = this->world.board[this->posX + 1][this->posY];
		this->world.board[this->posX + 1][this->posY] = nullptr;
		if (animalToDelete != nullptr)
			this->world.logs.push_front(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();

	}
	if (this->posY > 0 && dynamic_cast<Animal*>(this->world.board[this->posX][this->posY -1]) != nullptr) {
		Organism* animalToDelete = this->world.board[this->posX][this->posY -1];
		this->world.board[this->posX][this->posY-1] = nullptr;
		if (animalToDelete != nullptr)
			this->world.logs.push_front(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();


	}
	if (this->posY + 1 < this->world.b && dynamic_cast<Animal*>(this->world.board[this->posX][this->posY + 1]) != nullptr) {
		Organism* animalToDelete = this->world.board[this->posX][this->posY + 1];
		this->world.board[this->posX][this->posY + 1] = nullptr;
		if (animalToDelete != nullptr)
			this->world.logs.push_front(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();


	}
	Plant::act();
}