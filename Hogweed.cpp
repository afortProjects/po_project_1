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
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	if (this->posX > 0 && dynamic_cast<Animal*>(board[this->posX - 1][this->posY]) != nullptr) {
		Organism* animalToDelete = board[this->posX - 1][this->posY];
		board[this->posX - 1][this->posY] = nullptr;
		if(animalToDelete != nullptr)
			this->world.addLog(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();


	}
	if (this->posX + 1 < this->world.getA() && dynamic_cast<Animal*>(board[this->posX + 1][this->posY]) != nullptr) {
		Organism* animalToDelete = board[this->posX + 1][this->posY];
		board[this->posX + 1][this->posY] = nullptr;
		if (animalToDelete != nullptr)
			this->world.addLog(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();

	}
	if (this->posY > 0 && dynamic_cast<Animal*>(board[this->posX][this->posY - 1]) != nullptr) {
		Organism* animalToDelete = board[this->posX][this->posY - 1];
		board[this->posX][this->posY - 1] = nullptr;
		if (animalToDelete != nullptr)
			this->world.addLog(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();


	}
	if (this->posY + 1 < this->world.getB() && dynamic_cast<Animal*>(board[this->posX][this->posY + 1]) != nullptr) {
		Organism* animalToDelete = board[this->posX][this->posY + 1];
		board[this->posX][this->posY + 1] = nullptr;
		if (animalToDelete != nullptr)
			this->world.addLog(animalToDelete->getName() + " was just killed by Hogweed.");
		if (animalToDelete->getName() == "Human") this->world.endGame();

	}

	this->world.setBoard(board);

	Plant::act();
}