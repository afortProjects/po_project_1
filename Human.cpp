#include "Human.h"
#include "World.h"
#include<iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

Human::Human(World& world) : world(world), Animal(world, true) {
	world.board[0][0] = this;
	this->posX = 0;
	this->posY = 0;
}

void Human::draw() {
	printf("H");
}

void Human::act() {
	//Handle user input
	int newInput, newInput2;
	this->beforeMoveX = this->posX;
	this->beforeMoveY = this->posY;
	newInput = _getch();
	if (newInput == 0 || newInput == 224) {
		newInput2 = _getch();
		switch (newInput2) {
		case KEY_UP:
			this->posY--;
			break;
		case KEY_DOWN:
			this->posY++;
			break;
		case KEY_LEFT:
			this->posX--;
			break;
		case KEY_RIGHT:
			this->posX++;
			break;
		}
	}
		

	//Check if in board

	if (this->posX < 0)	this->posX = 0;
	if (this->posY < 0) this->posY = 0;

	if (this->posX > this->world.a - 1) this->posX--;
	if (this->posY > this->world.b - 1) this->posY--;

	if (this->world.board[this->posX][this->posY] != nullptr && this->posX != this->beforeMoveX && this->posY != this->beforeMoveY) collision();

}

void Human::collision() {
	//Handle special ability and check for collision with other objects

	Animal::collision();
}
Human::~Human() {
	exit(0);
}