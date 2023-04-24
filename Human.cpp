#include "Human.h"
#include "World.h"
#include<iostream>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define ABILITY_STRENGTH 10
#define BASE_STRENGTH 5
#define ABILITY_COOLDOWN 5

Human::Human(World& world) : Animal(world, true) {
	std::vector<std::vector<Organism*>> board = this->world.getBoard();
	board[0][0] = this;
	this->posX = 0;
	this->posY = 0;
	this->initiative = 4;
	this->strength = 5;
	this->name = "Human";
	this->world.setBoard(board);
}

void Human::draw() {
	printf("H");
}

void Human::handleInput() {
	int newInput2 = _getch();
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

void Human::act() {
	//Handle user input
	int newInput, newInput2;
	this->beforeMoveX = this->posX;
	this->beforeMoveY = this->posY;

	if (this->isAbilityTurnedOn) {
		this->abilityCooldown = ABILITY_COOLDOWN;
		if (this->strength == BASE_STRENGTH) {
			this->isAbilityTurnedOn = false;
		}
		else this->strength--;
	}
	else {
		if (this->abilityCooldown > 0) {
			this->abilityCooldown--;
		}
	}

	while (this->posX == this->beforeMoveX && this->posY == this->beforeMoveY) {
		newInput = _getch();
		

		if (newInput == 0 || newInput == 224) {
			handleInput();
		}
		else if (newInput == 'v') {
			Human::abillity();
			gotoxy(this->world.getA() * (SCALE_X + 1) + 50, 4);
			printf("Strength: %d\n", this->strength);
		}
		else if (newInput == 's') {
			this->world.save();
		}
	}
	
	//Check if in board

	if (this->posX < 0)	this->posX = 0;
	if (this->posY < 0) this->posY = 0;

	if (this->posX > this->world.getA() - 1) this->posX--;
	if (this->posY > this->world.getB() - 1) this->posY--;
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	if (board[this->posX][this->posY] != nullptr && this->posX != this->beforeMoveX && this->posY != this->beforeMoveY) collision();

}

void Human::abillity() {
	if (this->abilityCooldown == 0) {
		this->isAbilityTurnedOn = true;
		this->strength = ABILITY_STRENGTH;
		this->world.addLog("You have activated you super ability! ");
	}
}

void Human::collision() {
	Animal::collision();
}
Human* Human::clone() {
	return new Human(this->world);
}

bool Human::getIsAbilityTurnedOn() {
	return this->isAbilityTurnedOn;
}
int Human::getAbilityCooldown() {
	return this->abilityCooldown;
}

void Human::setIsAbilityTurnedOn(bool value) {
	this->isAbilityTurnedOn = value;
}
void Human::setAbilityCooldown(int cooldown) {
	this->abilityCooldown= cooldown;

}

Human::~Human() {
}