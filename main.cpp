#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
using namespace std;

int main() {
	
	int a, b;
	printf("Give a, b: ");
	cin >> a >> b;
	World world{ a,b };
	world.drawBoard();

	while (world.isRunning) {
		world.makeATurn();
	}
	return 0;
}