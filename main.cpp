#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
using namespace std;

int main() {
	
	int a, b;
	//system("mode 650");
	printf("Give a, b: ");
	cin >> a >> b;
	clearscreen();
	World world{ a,b };
	world.drawBoard();

	while (world.isRunning) {
		world.makeATurn();
	}
	return 0;
}