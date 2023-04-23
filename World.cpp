#include "World.h"
#include "Plant.h"
#include "Wolf.h"
#include "Sheep.h"
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

	//Animal* animal = new Animal(*this);
	//Animal* animal2 = new Animal(*this);
	Animal* animal3 = new Sheep(*this);
	Animal* animal4 = new Wolf(*this);
	//Plant* plant = new Plant(*this);

	this->human = new Human(*this);

}
//
//void World::fight(Organism* firstOrganism, Organism* secondOrganism) {
//	//Handle if 2 objects are in the same place
//	//If objects are of the same class -> breeding
//	//Else there is a fight
//
//	//Jesli moge rzutowac na animal -> to sprawdzamy breeding
//	//Jesli 
//	
//}

void World::makeATurn() {
	//Invoke act on all objects considering their initiative and age
	//Invoke collision on all objects that are in the same field

	std::vector<Organism*> boardWithOrganismsOnly;
	
	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			if (board[i][j] != nullptr) {
				boardWithOrganismsOnly.push_back(this->board[i][j]);
			}
		}
		//sif (dynamic_cast<Organism*>(this->board[i]) == nullptr)
	}

	//Now we have to sort bordWithOrganismsOnly by their initiatives and age
	std::sort(boardWithOrganismsOnly.begin(), boardWithOrganismsOnly.end(), [](
	  Organism* left, Organism* right) -> bool {
			if (left->initiative == right->initiative) return (left->age < right->age);
			return (left->initiative < right->initiative);
		});

	for (size_t i = boardWithOrganismsOnly.size()-1; i >= 0; i--) {
		boardWithOrganismsOnly[i]->act();
		boardWithOrganismsOnly[i]->age++;
		if (i == 0) break;
	}

	//for (size_t i = 0; i < a; i++) {
	//	for (size_t j = 0; j < b; j++) {
	//		for (size_t k = 0; k < a; k++) {
	//			for (size_t l = 0; l < b; l++) {
	//				if (board[i][j] && board[k][l] != nullptr) {
	//					if (board[i][j]->getPosX() == board[k][l]->getPosX() && board[i][j]->getPosY() == board[k][l]->getPosY() && i != k && j != l) {
	//						//Make collision take organism object as parametr
	//						this->fight(board[i][j], board[k][l]);
	//					}
	//				}
	//			} 
	//		}
	//	}
	//}

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			Organism* currentOrganism = this->board[i][j];
			if (currentOrganism != nullptr) {
				this->board[i][j] = nullptr;
				this->board[currentOrganism->getPosX()][currentOrganism->getPosY()] = currentOrganism;
			}

		}
	}

	//this->human->collision();

	drawBoard();
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
					if (this->board[j / (SCALE_X + 1)][i / SCALE_Y] != nullptr) {
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
	showCursor();
	gotoxy(0, 40);
	printf("Current x, y: %d, %d", this->human->posX / (SCALE_X+1), this->human->posY / SCALE_Y);
	gotoxy(this->human->posX, this->human->posY);

}

World::~World() {
	//Clear board, human
}