#pragma once
#include "Organism.h"
#include<vector>
class World {
public:
	int a, b;
	std::vector<Organism*> board;
	World(int a, int b);
	void makeATurn();
	void drawBoard();
	~World();
};