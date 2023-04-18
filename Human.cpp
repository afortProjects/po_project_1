#include "Human.h"
#include "World.h"
#include<iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
Human::Human(World* world) {
	this->world = world;
}

void Human::act() {
	//Handle user input, checking if user didn't go out of board
	char newInput;
	newInput = _getch();
	switch(newInput) {
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

	//Check if in board

	if (this->posX < 1) posX = 1;
	if (this->posY < 1) posY = 1;
	if (this->posX >= this->world->a) posX = this->world->a;

	if (this->posY >= this->world->b) posY = this->world->b;


}

void Human::collision() {
	//Handle special ability
}
Human::~Human() {

}