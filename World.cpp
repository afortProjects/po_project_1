#define _CRT_SECURE_NO_WARNINGS
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
#include <fstream>
#include <string>
World::World(int a, int b) : a(a), b(b) {
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

World::World() {
	load();
}

void World::makeATurn() {
	clearscreen();
	drawBoard();
	printLegend();
	printLogs();
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
			if (left->getInitiative() == right->getInitiative()) return (left->getAge() < right->getAge());
			return (left->getInitiative() < right->getInitiative());
		});

	for (int i = boardWithOrganismsOnly.size() - 1; i >= 0; i--) {
		if (boardWithOrganismsOnly[i] != nullptr) {
			boardWithOrganismsOnly[i]->setAge(boardWithOrganismsOnly[i]->getAge()+1);
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

void World::save() {
	clearscreen();
	std::string fileName, logsFileName;
	std::cout << "Your file name: ";
	std::cin >> fileName;
	std::cout << std::endl;
	logsFileName += fileName + "_logs.txt";
	fileName += ".txt";
	std::ofstream outputFile(fileName, std::ios::out);
	std::ofstream logsOutputFile(logsFileName, std::ios::out);

	//Save a, b
	outputFile << this->a << ' ';
	outputFile << this->b << ' ';
	outputFile << '\n';

	logsOutputFile << this->logs.size();
	logsOutputFile << '\n';
	for (auto& i : this->logs) {
		logsOutputFile << i << '\n';
	}
	//Save organisms
	std::string tempName = "";
	bool isAbilityOnCooldown;
	int tempNameSize, tempX, tempY, tempBeforeMoveX, tempBeforeMoveY, tempAge, null_value_int = 0, abilityCooldown, humanStrength;
	char null_value[] = "NULL";
	char name[256];
	const char* tempNameInChar;
	for (size_t i = 0; i < this->a; i++) {
		for (size_t j = 0; j < this->b; j++) {
			if (this->board[i][j] == nullptr) {
				outputFile << null_value_int << ' ';
				outputFile << null_value << ' ';
				outputFile << '\n';
			}
			else {
				tempName = this->board[i][j]->getName();
				tempNameSize = tempName.size();

				tempX = this->board[i][j]->getPosX();
				tempY = this->board[i][j]->getPosY();

				tempBeforeMoveX = this->board[i][j]->getBeforeMoveX();
				tempBeforeMoveY = this->board[i][j]->getBeforeMoveY();

				tempAge = this->board[i][j]->getAge();

				outputFile << tempNameSize << ' ';
				outputFile << tempName << ' ';
				outputFile << tempX << ' ';
				outputFile << tempY << ' ';
				outputFile << tempBeforeMoveX << ' ';
				outputFile << tempBeforeMoveY << ' ';
				outputFile << tempAge << ' ';
				if (tempName == "Human") {
					isAbilityOnCooldown = dynamic_cast<Human*>(this->board[i][j])->getIsAbilityTurnedOn();
					abilityCooldown = dynamic_cast<Human*>(this->board[i][j])->getAbilityCooldown();
					humanStrength = dynamic_cast<Human*>(this->board[i][j])->getStrength();

					outputFile << isAbilityOnCooldown << ' ';
					outputFile << abilityCooldown << ' ';
					outputFile << humanStrength << ' ';

				}
				outputFile << '\n';
			}
		}
	}

	outputFile.close();

	exit(0);
}

void World::load() {
	clearscreen();
	std::string fileName, logsFileName;
	std::cout << "Your file name: ";
	std::cin >> fileName;
	std::cout << std::endl;
	logsFileName += fileName + "_logs.txt";
	fileName += ".txt";

	std::ifstream inputFile(fileName, std::ios::in);
	std::ifstream logsInputFile(logsFileName, std::ios::in);

	int a, b;
	std::deque<std::string> logs;
	this->logs = logs;
	inputFile >> a;
	inputFile >> b;

	int logsSize;
	logsInputFile >> logsSize;
	std::string tempLog;

	for (int i = 0; i < logsSize; i++) {
		//inputFile >> std::noskipws >> tempLog;
		std::getline(logsInputFile, tempLog);
		this->logs.push_back(tempLog);
		tempLog = "";
	}

	this->a = a;
	this->b = b;
	for (size_t i = 0; i < a; i++) {
		std::vector<Organism*> temp;
		for (size_t j = 0; j < b; j++) {
			temp.push_back(nullptr);
		}
		this->board.push_back(temp);
	}

	bool isAbilityTurnedOn;
	int posX, posY, beforeMoveX, beforeMoveY, age, nameSize, abilityCooldown, humanStrength;
	std::string name = "";
	Organism* newOrganism;

	for (size_t i = 0; i < a; i++) {
		for (size_t j = 0; j < b; j++) {
			nameSize = 0;
			posX = 0;
			posY = 0;
			beforeMoveX = 0;
			beforeMoveY = 0;
			age = 0;
			name = "";

			inputFile >> nameSize;
			inputFile >> name;

			if (name == "NULL") {
				this->board[i][j] = nullptr;
				continue;
			}
			else {
				newOrganism = nullptr;
				if (name == "Antilope") {
					newOrganism = new Antilope(*this);
				}
				else if (name == "Blueberry") {
					newOrganism = new Blueberry(*this);
				}
				else if (name == "Dandelion") {
					newOrganism = new Dandelion(*this);
				}
				else if (name == "Fox") {
					newOrganism = new Fox(*this);
				}
				else if (name == "Grass") {
					newOrganism = new Grass(*this);
				}
				else if (name == "Guarana") {
					newOrganism = new Guarana(*this);
				}
				else if (name == "Hogweed") {
					newOrganism = new Hogweed(*this);
				}
				else if (name == "Human") {
					newOrganism = new Human(*this);
				}
				else if (name == "Sheep") {
					newOrganism = new Sheep(*this);
				}
				else if (name == "Turtle") {
					newOrganism = new Turtle(*this);
				}
				else if (name == "Wolf") {
					newOrganism = new Wolf(*this);
				}
				if (newOrganism != nullptr) {
					this->board[newOrganism->getPosX()][newOrganism->getPosY()] = nullptr;

					inputFile >> posX;
					inputFile >> posY;

					inputFile >> beforeMoveX;
					inputFile >> beforeMoveY;

					inputFile >> age;
					
					if (name == "Human") {
						inputFile >> isAbilityTurnedOn;
						inputFile >> abilityCooldown;
						inputFile >> humanStrength;

						dynamic_cast<Human*>(newOrganism)->setAbilityCooldown(abilityCooldown);
						dynamic_cast<Human*>(newOrganism)->setIsAbilityTurnedOn(isAbilityTurnedOn);
						dynamic_cast<Human*>(newOrganism)->setStrength(humanStrength);
						
						this->human = dynamic_cast<Human*>(newOrganism);
					}


					newOrganism->setAge(age);

					newOrganism->setPosX(posX);
					newOrganism->setPosY(posY);

					newOrganism->setBeforeMoveX(beforeMoveX);
					newOrganism->setBeforeMoveY(beforeMoveY);

					this->board[i][j] = newOrganism;
				}

			}
		}
		
	}

	inputFile.close();
}

std::vector<std::vector<Organism*>> World::getBoard() {
	return this->board;
}

int World::getA() {
	return this->a;
}

int World::getB() {
	return this->b;
}

bool World::getState() {
	return this->isRunning;
}

void World::addLog(std::string message) {
	this->logs.push_front(message);
}

void World::setBoard(std::vector<std::vector<Organism*>> newBoard) {
	this->board = newBoard;
}

World::~World() {
	//Clear board, human
}