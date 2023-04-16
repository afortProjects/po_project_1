#pragma once
#include "Organism.h"

class Plant : Organism {
protected: 
	int initiative = 0;
public:
	void act() override;
	void collision() override;
	void draw() override;
	~Plant();
};