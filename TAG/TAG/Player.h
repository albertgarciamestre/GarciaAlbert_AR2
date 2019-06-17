 #pragma once
#include "Map.h"
#include "Types.h"

class Player
{
public:
	int xPos, yPos, firstX, firstY;
	bool newGame = false;
	Player();
	void movePlayer(int, char**);
};
