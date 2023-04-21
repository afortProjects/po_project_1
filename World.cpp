#include "World.h"
#include "output.h"
#include <iostream>
#include <vector>
#include <algorithm>

World::World(int a, int b) {
	this->a = a;
	this->b = b;
	//1d array of size a * b of pointers that wil be used as 2d array
	for (size_t i = 0; i < a * b; i++) {
		this->board.push_back(nullptr);
	}
	Animal* animal = new Animal(this);
	Animal* animal2 = new Animal(this);
	Animal* animal3 = new Animal(this);
	Animal* animal4 = new Animal(this);


	this->human = new Human(this);

} 

bool World::compareTwoOrganisms(Organism* a, Organism* b) {
	return (a->initiative < b->initiative);
}

void World::makeATurn() {
	//Invoke act on all objects considering their initiative and age
	//Invoke collision on all objects that are in the same field
	this->human->act();
	std::vector<Organism*> boardWithOrganismsOnly;
	for (size_t i = 0; i < a * b; i++) {
		//Consider initiative and age
		//if (dynamic_cast<Organism*>(this->board[i]) == nullptr)
		if (board[i] == nullptr) {
			//Organism object here
		}
		else {
			//Consider initiative
			boardWithOrganismsOnly.push_back(this->board[i]);
		}
	}

	//Now we have to sort bordWithOrganismsOnly by their initiatives
	std::sort(boardWithOrganismsOnly.begin(), boardWithOrganismsOnly.end());

	for (size_t i = 0; i < boardWithOrganismsOnly.size(); i++) {
		boardWithOrganismsOnly[i]->act();
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
}

void World::drawBoard() {

	//clearscreen();

	int spacesCounter;
	int dashCounter = 0;

	hideCursor();
	gotoxy(0, 0);
	for (size_t i = 0; i < this->b * SCALE_Y; i++) {
		spacesCounter = 0;
		for (size_t j = 0; j < this->a * (SCALE_X + 1); j++) {
			if (i % 2 == 0) {
				if (j % (SCALE_X + 1) == 0) {
					int k = (i / SCALE_Y) * (this->a) + (j / (SCALE_X + 1)); // 4 * 3 = 12 + 2 = 14
					if (this->board[k] != nullptr) {
						printf("A");
					}
					else {
						printf(" ");
					}
					spacesCounter++;
				}
				else if (spacesCounter != this->a) {
					printf("-");
				}
			}
			else {
				if (j % (SCALE_X + 1) == 0 && dashCounter + 1 != this->b) {
					printf("|");
				}
				else  {
					printf(" ");
				}
				
			}
		}
		if (i % 2 == 1) dashCounter++;
		printf("\n");
	}
	showCursor();
	gotoxy(0, 40);
	printf("Current x, y: %d, %d", this->human->posX / (SCALE_X+1), this->human->posY / SCALE_Y);
	gotoxy(this->human->posX, this->human->posY);

}

World::~World() {

}