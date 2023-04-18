#pragma once
class World;

class Organism {
protected:
	World* world = nullptr;
	int posX=0, posY=0, age=0, strength=0, initiative=0;
public:
	Organism();
	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int getPosX();
	int getPosY();
	~Organism();
};