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
	if (tempX >= 0 && tempX < this->world.a && tempY >= 0 && tempY < this->world.b) {
		this->posX = tempX;
		this->posY = tempY;
		this->world.logs.push_front(this->name + " moved to " + std::to_string(this->posX) + ", " + std::to_string(this->posY));
	}

	if (this->world.board[this->posX][this->posY] != nullptr && this->world.board[this->posX][this->posY] != this) collision();

}

void Antilope::collision() {
	if (rand() % 2) {
		//Antilope runs from fight
		if (this->posX + 1 < this->world.a && this->world.board[this->posX + 1][this->posY] == nullptr) {
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX + 1][this->posY] = this;
			this->posX++;
			this->world.logs.push_front(this->getName() + " just ran.");

		} else if (this->posX > 0 && this->world.board[this->posX - 1][this->posY] == nullptr) {
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX - 1][this->posY] = this;
			this->posX--;
			this->world.logs.push_front(this->getName() + " just ran.");

		}
		else if (this->posY + 1 < this->world.b && this->world.board[this->posX][this->posY+1] == nullptr) {
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX][this->posY+1] = this;
			this->posY++;
			this->world.logs.push_front(this->getName() + " just ran.");

		}
		else if (this->posY > 0 && (this->world.board[this->posX][this->posY-1] == nullptr)) {
			this->world.board[this->beforeMoveX][this->beforeMoveY] = nullptr;
			this->world.board[this->posX][this->posY-1] = this;
			this->posY--;
			this->world.logs.push_front(this->getName() + " just ran.");

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