#pragma once
#include "Map.h"
#include "Types.h"
class Player2F
{
public:
	int xPos, yPos, firstX, firstY;
	bool newGame = false;
	Player2F();
	void movePlayer2F(int, char**);
};

