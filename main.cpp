#include <iostream>
#include "Organism.h"
#include "World.h"
#include "Animal.h"
#include "Human.h"
#include "Plant.h"
using namespace std;

int main() {
	int a, b;
	cout << "Give a, b: ";
	cin >> a >> b;
	World world{ a,b };
	world.makeATurn();
	world.drawBoard();
	return 0;
}