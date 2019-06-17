#include "Map.h"
Map::Map()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	std::ifstream myFile("config.txt");

	char a;

	while (!myFile.eof())
	{
		myFile >> numRows >> a >> numColumns>> a;
		std::getline(myFile, mapStr, '\0');
	}

	myFile.close();
	map = new char*[numRows];
	for (int i = 0; i < numRows+1; ++i)
		map[i] = new char[numColumns];

	for (int i = 0; i < numRows; ++i) {
		for (int j = 1; j < numColumns + 1; ++j)
		{
			if (mapStr[i*(numColumns + 1) + j] == 'X') {
				map[i][j] = 'X';

			}

			else if (mapStr[i*(numColumns + 1) + j] == ' ') {
				map[i][j] = ' ';
			}
			else if (mapStr[i*(numColumns + 1) + j] == '#') {
				map[i][j] = '#';
				firstX3 = i;
				firstY3 = j;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			}
			else if (mapStr[i*(numColumns + 1) + j] == '&') {
				map[i][j] = '&';
				firstX2 = i;
				firstY2 = j;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

			}
			
		}

	}
}

void  Map::resetBoard()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < numRows; ++i) {
		for (int j = 1; j < numColumns + 1; ++j)
		{
			map[i][j] = ' ';
		}
	}

	std::ifstream myFile("config.txt");

	char a;

	while (!myFile.eof())
	{
		myFile >> numRows >> a >> numColumns >> a;
		std::getline(myFile, mapStr, '\0');
	}

	myFile.close();
	map = new char*[numRows];
	for (int i = 0; i < numRows; ++i)
		map[i] = new char[numColumns];

	for (int i = 0; i < numRows; ++i) {
		for (int j = 1; j < numColumns + 1; ++j)
		{
			if (mapStr[i*(numColumns + 1) + j] == 'X') {
					map[i][j] = 'X';
			

			}

			else if (mapStr[i*(numColumns + 1) + j] == ' ') {
				map[i][j] = ' ';
			}
			else if (mapStr[i*(numColumns + 1) + j] == '#') {
				map[i][j] = '#';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

			}
			else if (mapStr[i*(numColumns + 1) + j] == '&') {
				map[i][j] = '&';
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

			}
		}
	}
}

void  Map::updateBoard()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);


	
	for (int i = 0; i <numRows;i++)
	{
		std::cout << std::endl;
		for (int j = 0; j <=numColumns;j++)
		{
			switch (map[i][j])
			{
			case ' ':
				SetConsoleTextAttribute(console, 1);
				std::cout << ' ';
				break;
			case '&':
				SetConsoleTextAttribute(console, 13);
				std::cout << '&';
				break;
			case '#':
				SetConsoleTextAttribute(console, 10);
				std::cout << '#';
				break;
			case 'X':
				SetConsoleTextAttribute(console, 1);
				std::cout << char(219);
				break;
			default: SetConsoleTextAttribute(console, 1); break;
			}

		}

	}
	SetConsoleTextAttribute(console, 1);
	std::cout << std::endl;
}
/*Map::~Map() //lliberem la memoria del heap
{
	for (int i = 0; i < numRows; ++i) {
		delete[] map[i];
	}
	delete[] map;
	map = nullptr;
}*/
