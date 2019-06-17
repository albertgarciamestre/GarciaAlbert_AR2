#include "Player2F.h"


Player2F::Player2F()
{
	Map map;

	for (int i = 5; i < map.numRows; ++i) {
		for (int j = 5; j < map.numColumns + 1; ++j)
		{
			if (map.map[i][j] == '&')
			{
				firstX = i;
				xPos = i;
				firstY = j;
				yPos = j;
			}
		}
	}
}

void Player2F::movePlayer2F(int dir, char** map)
{
	if (map[xPos][yPos] == '#')
	{
		newGame = true;
	}

	if (dir == Movement::LEFT && map[xPos][yPos - 1] != 'X')
	{
		map[xPos][yPos] = ' ';

		if (map[xPos][yPos - 1] == '#') {
			newGame = true;
		}

		yPos--;
		if (yPos == 0)
		{
			yPos = 15;
		}
	}
	else if (dir == Movement::RIGHT && map[xPos][yPos + 1] != 'X')
	{
		map[xPos][yPos] = ' ';




		if (map[xPos][yPos + 1] == '#') {
			newGame = true;

		}


		yPos++;
		if (yPos == 16)
		{
			yPos = 1;
		}
	}
	else if (dir == Movement::DOWN)
	{
		if (xPos == 14)
		{
			map[xPos][yPos] = ' ';
			xPos = 0;
			map[xPos][yPos] = '&';
			return;
		}

		if (map[xPos + 1][yPos] == '#')
		{
			newGame = true;
		}

		if (map[xPos + 1][yPos] != 'X')
		{
			map[xPos][yPos] = ' ';
			xPos++;
		}

	}
	else if (dir == Movement::UP && map[xPos - 1][yPos] != 'X')
	{
		map[xPos][yPos] = ' ';
		if (map[xPos - 1][yPos] == '#') {
			newGame = true;
		}


		xPos--;
		if (xPos == 0)
		{
			xPos = 14;
		}
	}
	map[xPos][yPos] = '&';
}
