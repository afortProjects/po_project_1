#pragma once
#include "Organism.h"
#include "Human.h"
#include "Animal.h"
#include<vector>
class World {
public:
	int a, b;
	std::vector<Organism*> board;
	bool isRunning = true;
	Human* human;
	World(int a, int b);
	void makeATurn();
	void drawBoard();
	~World();
};