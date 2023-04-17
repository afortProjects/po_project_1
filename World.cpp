#include "World.h"
#include "Organism.h"
#include "Animal.h"
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
	//for (size_t i = 0; i < a * b; i++) {
	//	for (size_t j = 0; j < a * b; j++) {
	//		//Consider initiative and age
	//		if (board[i] != nullptr) {
	//			if (board[i]->getPosX() == board[j]->getPosX() && board[i]->getPosY() == board[j]->getPosY() && i != j)
	//				board[i]->collision();
	//		}
	//	}
	//}


}

void World::drawBoard() {
	//Draw board
	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			//To operate on 1d array as on 2d array
			int k = i * this->b + j; 
			if (this->board[k] != nullptr) {
				if (dynamic_cast<Animal*>(this->board[k]) != nullptr) {
					//Object is animal
					std::cout << 'A';
				}
			}
			else {
				std::cout << '_';
			}
		}
		std::cout << '\n';

	}
}

World::~World() {

}