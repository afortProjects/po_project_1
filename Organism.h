#pragma once
class World;

class Organism {
protected:
	World* world = nullptr;
	int posX = 0, posY = 0, strength = 0;
public:
	int initiative = 0, age = 0, positionInBoard;
	Organism();
	Organism(World* world);

	void virtual act() = 0;
	void virtual collision() = 0;
	void virtual draw() = 0;
	int getPosX();
	int getPosY();
	bool operator >(const Organism* object);
	~Organism();
};