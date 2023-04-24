#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
using namespace std;

int main() {
	srand(time(0));
	int a, b, choice;
	//system("mode 650");
	cout << "Menu: \n";
	cout << "1. Start new game\n";
	cout << "2. Load game from file\n";
	cin >> choice;
	if (choice == 1) {
		printf("Give a, b: ");
		cin >> a >> b;
		World world{ a,b };
		clearscreen();
		world.drawBoard();
		world.printLegend();
		world.printLogs();

		while (world.isRunning) {
			world.makeATurn();
		}
	}
	else if (choice == 2) {
		World world{};

		clearscreen();
		world.drawBoard();
		world.printLegend();
		world.printLogs();

		while (world.isRunning) {
			world.makeATurn();
		}
	}
	return 0;
}