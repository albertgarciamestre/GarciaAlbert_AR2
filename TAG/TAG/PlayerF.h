#pragma once
#include "Map.h"
#include "Types.h"
class PlayerF
{
public:
	int xPos, yPos, firstX, firstY;
	bool newGame = false;
	PlayerF();
	void movePlayerF(int, char**);
};
