#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <Time.h>
#include "Player.h"

class Map
{
	bool endGame=true;
	std::string mapStr;
	int firstX1, firstY1;
	int firstX2, firstY2;
	int firstX3, firstY3;
public:
	int numColumns;
	bool paused;
	int numRows;
	char **map;
	bool powerUp = false;
	Map();
	void resetBoard();
	void updateBoard();


	//Destructor
	
};
