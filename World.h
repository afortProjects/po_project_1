#pragma once
#include "Organism.h"
class World {
public:
	Organism** board;
	void makeATurn();
	void drawBoard();
	~World();
};