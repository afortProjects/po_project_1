#pragma once
#include "Plant.h"
class Blueberry : public Plant {
public:
	Blueberry(World& World);
	void draw();
	Blueberry* clone();
};