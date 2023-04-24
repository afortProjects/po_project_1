#include "Organism.h"
#include <iostream>
#include "World.h"

Organism::Organism(World& world) : world(world) {
	//Constructor
	this->posX = floor(rand() % world.a);
	this->posY = floor(rand() % world.b);

	//Check if place is not occupied
	while (this->world.board[this->posX][this->posY] != nullptr) {
		this->posX = floor(rand() % this->world.a);
		this->posY = floor(rand() % this->world.b);
	}

	this->world.board[this->posX][this->posY] = this;
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

//std::ostream& operator<<(std::ostream& os, const Organism* obj) {
//	os << obj.name << " " << obj.age << std::endl;
//	return os;
//}
//
//std::istream& operator>>(std::istream& is, const Organism* obj) {
//	is >> obj.name >> obj.age << std::endl;
//	return is;
//}

Organism::~Organism() {
	
}