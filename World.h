#pragma once
#include "Organism.h"
#include "Human.h"
#include "Animal.h"
#include<vector>

#define SCALE_X 3
#define SCALE_Y 2

class World {
public:
	int a, b;
	std::vector<std::vector<Organism*>> board;
	bool isRunning = true;
	Human* human;

	World(int a, int b);
	void makeATurn();
	void drawBoard();
	~World();
};