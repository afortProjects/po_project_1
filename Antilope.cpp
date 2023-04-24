#include "Antilope.h"
#include "World.h"
#include <string>
Antilope::Antilope(World& world) : Animal(world) {
	this->strength = 4;
	this->initiative = 4;
	this->name = "Antilope";
}
Antilope* Antilope::clone() {
	return new Antilope (this->world);
}
	
void Antilope::draw() {
	printf("A");
}

void Antilope::act() {
	int tempX = this->posX;
	int tempY = this->posY;
	this->beforeMoveX = tempX;
	this->beforeMoveY = tempY;
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
	if (tempX >= 0 && tempX < this->world.getA() && tempY >= 0 && tempY < this->world.getB()) {
		this->posX = tempX;
		this->posY = tempY;
		this->world.addLog(this->name + " moved to " + std::to_string(this->posX) + ", " + std::to_string(this->posY));
	}
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	if (board[this->posX][this->posY] != nullptr && board[this->posX][this->posY] != this) collision();

}

void Antilope::collision() {
	std::vector<std::vector<Organism*>> board = this->world.getBoard();
	if (rand() % 2) {
		//Antilope runs from fight
		if (this->posX + 1 < this->world.getA() && board[this->posX + 1][this->posY] == nullptr) {
			board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			board[this->posX + 1][this->posY] = this;
			this->posX++;
			this->world.addLog(this->getName() + " just ran.");

		}
		else if (this->posX > 0 && board[this->posX - 1][this->posY] == nullptr) {
			board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			board[this->posX - 1][this->posY] = this;
			this->posX--;
			this->world.addLog(this->getName() + " just ran.");

		}
		else if (this->posY + 1 < this->world.getB() && board[this->posX][this->posY + 1] == nullptr) {
			board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			board[this->posX][this->posY + 1] = this;
			this->posY++;
			this->world.addLog(this->getName() + " just ran.");

		}
		else if (this->posY > 0 && (board[this->posX][this->posY - 1] == nullptr)) {
			board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			board[this->posX][this->posY-1] = this;
			this->posY--;
			this->world.addLog(this->getName() + " just ran.");

		}
		else {
			//If there is no available place, there is fight
			Animal::collision();
		}
	}
	else {
		Animal::collision();
	}
	this->world.setBoard(board);


}