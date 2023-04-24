#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism(World& world) : world(world) {
	//Constructor
	int a = world.getA();
	int b = world.getB();

	this->posX = floor(rand() % a);
	this->posY = floor(rand() %b);

	//Check if place is not occupied
	std::vector<std::vector<Organism*>> board = this->world.getBoard();

	while (board[this->posX][this->posY] != nullptr) {
		if (!(this->world.checkIfThereIsPlaceAvailable())) {
			this->world.endGame("There is no available space. ");
		}
		this->posX = floor(rand() % a);
		this->posY = floor(rand() % b);
	}

	board[this->posX][this->posY] = this;

	this->world.setBoard(board);

}

Organism::Organism(World& world, bool isHuman) : world(world) {

}

int Organism::addStrength() {
	return 0;
}

Organism* clone() {
	return nullptr;
}

void Organism::setPosX(int x) {
	this->posX = x;
}

void Organism::setPosY(int y) {
	this->posY = y;
}

void Organism::setBeforeMoveX(int x) {
	this->beforeMoveX = x;
}

void Organism::setBeforeMoveY(int y) {
	this->beforeMoveY = y;
}

void Organism::setStrength(int newStrength) {
	this->strength = newStrength;
}

void Organism::setAge(int age) {
	this->age = age;
}

int Organism::getPosX() {
	return this->posX;
}

int Organism::getPosY() {
	return this->posY;
}

int Organism::getBeforeMoveX() {
	return this->beforeMoveX;
}

int Organism::getBeforeMoveY() {
	return this->beforeMoveY;
}

int Organism::getAge() {
	return this->age;
}

int Organism::getStrength() {
	return this->strength;
}

std::string Organism::getName() {
	return this->name;
}

int Organism::getInitiative() {
	return this->initiative;
}

Organism::~Organism() {
	
}