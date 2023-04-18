#include "World.h"
#include "output.h"
#include <iostream>
World::World(int a, int b) {
	this->a = a;
	this->b = b;
	Animal* animal = new Animal();
	//1d array of size a * b of pointers that wil be used as 2d array
	for (size_t i = 0; i < a * b; i++) {
		if (i % 10 == 0) {
			this->board.push_back(animal);
		}
		else {
			this->board.push_back(nullptr);
		}
	}

	this->human = new Human(this);

} 

void World::makeATurn() {
	//Invoke act on all objects considering their initiative and age
	//Invoke collision on all objects that are in the same field
	for (size_t i = 0; i < a * b; i++) {
		//Consider initiative and age
		//if (dynamic_cast<Organism*>(this->board[i]) == nullptr)
		if (board[i] == nullptr) {
			//Organism object here
		}
		else {
			this->board[i]->act();
		}
	}
	for (size_t i = 0; i < a * b; i++) {
		for (size_t j = 0; j < a * b; j++) {
			//Consider initiative and age
			if (board[i] != nullptr && board[j] != nullptr) {
				if (board[i]->getPosX() == board[j]->getPosX() && board[i]->getPosY() == board[j]->getPosY() && i != j)
					board[i]->collision();
			}
		}
	}
	drawBoard();
	this->human->act();
}

void World::drawBoard() {
	//Draw board
	clearscreen();

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			//To operate on 1d array as on 2d array
			int k = i * this->b + j; 
			gotoxy(i+1, j+1);
			if (this->board[k] != nullptr) {
				if (dynamic_cast<Animal*>(this->board[k]) != nullptr) {
					//Object is animal
					printf("A");
				}
			}
			else {
				printf("_");

			}
		}
	}
	gotoxy(0, 40);
	printf("Current x, y: %d, %d", this->human->posX, this->human->posY);
	gotoxy(this->human->posX, this->human->posY);

}

World::~World() {

}