#pragma once
#include "Organism.h"
#include "Human.h"
#include "Animal.h"
#include<vector>
#include <deque>

#define SCALE_X 3
#define SCALE_Y 2

class World {
private:
	int a, b;
	bool isRunning = true;
	Human* human;
	std::vector<std::vector<Organism*>> board;
	std::deque<std::string> logs;
public:
	World();
	World(int a, int b);
	void makeATurn();
	void endGame();
	void drawBoard();
	void printLogs();
	void printLegend();
	void save();
	void load();

	int getA();
	int getB();
	bool getState();
	std::vector<std::vector<Organism*>> getBoard();

	void setBoard(std::vector<std::vector<Organism*>> newBoard);
	void addLog(std::string message);

	~World();
};