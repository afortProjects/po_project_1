#pragma once
#include "Organism.h"

class Plant : public Organism {
protected: 
	int initiative = 0;
public:
	Plant();
	void act() override;
	void collision() override;
	void draw() override;
	~Plant();
};