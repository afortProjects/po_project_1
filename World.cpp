#include "World.h"
#include "Organism.h"
#include "Animal.h"
#include <iostream>
World::World(int a, int b) {
	this->a = a;
	this->b = b;
	Animal animal;
	//1d array of size a * b of pointers that wil be used as 2d array
	for (size_t i = 0; i < a * b; i++) {
		if (i % 10 == 0) {
			this->board.push_back(&animal);
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
		if (dynamic_cast<Organism*>(this->board[i]) == nullptr) {
			std::cout << "Object is organism class";
			//this->board[i]->act();
		}
	}
	//for (size_t i = 0; i < a * b; i++) {
	//	for (size_t j = 0; j < a * b; j++) {
	//		//Consider initiative and age
	//		if(board[i].X == board[j].X && i != j)
	//			board[i]->collision();
	//	}
	//}


}

void World::drawBoard() {
	//Draw board
}

World::~World() {

}