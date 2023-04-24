#include "World.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Antilope.h"
#include "Turtle.h"
#include "Human.h"

#include "Dandelion.h"
#include "Grass.h"
#include "Blueberry.h"
#include "Guarana.h"
#include "Hogweed.h"

#include "output.h"
#include <vector>
#include <iostream>
#include <algorithm>

World::World(int a, int b) {
	this->a = a;
	this->b = b;
	for (size_t i = 0; i < a; i++) {
		std::vector<Organism*> temp;
		for (size_t j = 0; j < b; j++) {
			temp.push_back(nullptr);
		}
		this->board.push_back(temp);
	}
	
	this->human = new Human(*this);
	Animal* animal1 = new Sheep(*this);
	Animal* animal6 = new Sheep(*this);

	Animal* animal2 = new Wolf(*this);
	Animal* animal3 = new Fox(*this);
	Animal* animal4 = new Antilope(*this);
	Animal* animal5 = new Turtle(*this);


	//Plant* plant1 = new Dandelion(*this);
	//Plant* plant2 = new Grass(*this);
	Plant* plant3 = new Guarana(*this);

	Plant* plant4 = new Blueberry(*this);
	Plant* plant5 = new Hogweed(*this);
}

void World::makeATurn() {
	//Invoke act on all objects considering their initiative and age
	std::vector<Organism*> boardWithOrganismsOnly;

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			if (board[i][j] != nullptr) {
				boardWithOrganismsOnly.push_back(this->board[i][j]);
			}
		}
	}

	//Now we have to sort bordWithOrganismsOnly by their initiatives and age
	std::sort(boardWithOrganismsOnly.begin(), boardWithOrganismsOnly.end(), [](
		Organism* left, Organism* right) -> bool {
			if (left->initiative == right->initiative) return (left->age < right->age);
			return (left->initiative < right->initiative);
		});

	for (int i = boardWithOrganismsOnly.size() - 1; i >= 0; i--) {
		if (boardWithOrganismsOnly[i] != nullptr) {
			boardWithOrganismsOnly[i]->age++;
			boardWithOrganismsOnly[i]->act();

			drawBoard();
		}
	}

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			Organism* currentOrganism = this->board[i][j];
			if (currentOrganism != nullptr) {
				if (this->board[currentOrganism->getPosX()][currentOrganism->getPosY()] != nullptr && currentOrganism != this->board[currentOrganism->getPosX()][currentOrganism->getPosY()]) currentOrganism->collision();
				else {
					this->board[i][j] = nullptr;
					this->board[currentOrganism->getPosX()][currentOrganism->getPosY()] = currentOrganism;
				}
			}
		}
	}
	clearscreen();
	drawBoard();
	printLegend();
	printLogs();
}

void World::endGame() {
	clearscreen();
	printf("You died.\n\n");
	exit(0);
}

void World::drawBoard() 
{
	int spacesCounter;
	int dashCounter = 0;

	hideCursor();
	gotoxy(0, 0);
	for (size_t i = 0; i < this->b * SCALE_Y; i++) {
		spacesCounter = 0;
		for (size_t j = 0; j < this->a * (SCALE_X + 1); j++) {
			if (i % 2 == 0) {
				if (j % (SCALE_X + 1) == 0) {
					//int k = (i / SCALE_Y) * (this->a) + (j / (SCALE_X + 1)); // 4 * 3 = 12 + 2 = 14
					if (this->board[j / (SCALE_X + 1)][i / SCALE_Y] != nullptr && this->board[j/(SCALE_X+1)][i/SCALE_Y]->getName() != "Human") {
						this->board[j / (SCALE_X + 1)][i / SCALE_Y]->draw();
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
	//showCursor();
	//gotoxy(0, 40);
	gotoxy(this->human->getPosX() * (SCALE_X + 1) + 1, this->human->getPosY() * SCALE_Y + 1);
	this->human->draw();
}

void World::printLogs() {
	gotoxy(this->a * (SCALE_X + 1) + 50, 1);
	printf("--------------------\n");
	gotoxy(this->a * (SCALE_X + 1) + 50, 2);
	printf("------- Logs -------\n");
	gotoxy(this->a * (SCALE_X + 1) + 50, 3);
	printf("Current x, y: %d, %d \n", this->human->getPosX(), this->human->getPosY());
	gotoxy(this->a * (SCALE_X + 1) + 50, 4);

	printf("Strength: %d\n", this->human->getStrength());

	for (int i = 0; i < this->logs.size() && i <= 15; i++) {
		gotoxy(this->a * (SCALE_X + 1) + 50, (i+5));
		printf("%d. %s\n",this->logs.size() - i, this->logs[i].c_str());
	}

	printf("--------------------\n");

}

void World::printLegend() {
	gotoxy(this->a*(SCALE_X+1) + 10, 1);
	printf("--------------------\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 2);
	printf("------ Legend ------\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 3);
	printf("--------------------\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 4);
	printf("------ Player ------\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 5);
	printf("H - Human\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 6);
	printf("------ Animals -----\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 7);
	printf("A - Antilope\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 8);
	printf("T - Turtle\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 9);
	printf("W - Wolf\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 10);
	printf("F - Fox\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 11);
	printf("S - Sheep\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 12);
	printf("------ Plants ------\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 13);
	printf("t - Grass\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 14);
	printf("b - Wilcze jagody\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 15);
	printf("h - Barszcz sosnowskiego\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 16);
	printf("g - Guarana\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 17);
	printf("d - Dandelion\n");
	gotoxy(this->a*(SCALE_X+1) + 10, 18);
	printf("--------------------\n");
	printf("------ Controls ------\n");
	gotoxy(this->a * (SCALE_X + 1) + 10, 19);
	printf("arrows - move\n");
	gotoxy(this->a * (SCALE_X + 1) + 10, 20);
	printf("v - special power\n");
	gotoxy(this->a * (SCALE_X + 1) + 10, 21);
	printf("--------------------\n");

}

World::~World() {
	//Clear board, human
}