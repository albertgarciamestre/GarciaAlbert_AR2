#pragma once

#include "Map.h"
#include "Types.h"
class Player2
{
public:
	int xPos, yPos, firstX, firstY;
	bool newGame = false;
	Player2();
	void movePlayer2(int, char**);
};
