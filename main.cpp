#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
using namespace std;

int main() {
	srand(time(0));
	int a, b;
	//system("mode 650");
	printf("Give a, b: ");
	cin >> a >> b;
	clearscreen();
	World world{ a,b };
	world.drawBoard();
	world.printLegend();
	world.printLogs();

	while (world.isRunning) {
		world.makeATurn();
	}
	return 0;
}