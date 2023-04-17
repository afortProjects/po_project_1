#pragma once
class Organism {
protected:
	//World& world;
	int posX, posY, age, strength, initiative;
public:
	Organism();
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	~Organism();
};