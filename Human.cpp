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
	//Handle user input
	char newInput;
	newInput = _getch();
	switch(newInput) {
		case KEY_UP:
			this->posY -= SCALE_Y;
			break;
		case KEY_DOWN:
			this->posY += SCALE_Y;
			break;
		case KEY_LEFT:
			this->posX -= SCALE_X+1;
			break;
		case KEY_RIGHT:
			this->posX += SCALE_X+1;
			break;
	}

	//Check if in board

	if (this->posX < 1)	this->posX = 1;
	if (this->posY < 1) this->posY = 1;

	if (this->posX > this->world->a * (SCALE_X+1)) this->posX -= SCALE_X+1;
	if (this->posY > this->world->b * SCALE_Y) this->posY = this->world->b*SCALE_Y-1;


}

void Human::collision() {
	//Handle special ability
}
Human::~Human() {

}