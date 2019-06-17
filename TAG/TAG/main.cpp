#include "Map.h"
#include "Player.h"
#include "Player2.h"
#include "PlayerF.h"
#include "Player2F.h"
#include <chrono>
#include "Utilities.h"
#include "Types.h"
#include <map>
#include <vector>
#include <time.h>
#include <ctime>

Player2F player2F;
Map map;
Player player;
PlayerF playerF;
Player2	player2;

void reset()
{
	player.xPos = player.firstX;
	player.yPos = player.firstY;

	playerF.xPos = playerF.firstX;
	playerF.yPos = playerF.firstY;

	player2.xPos = player2.firstX;
	player2.yPos = player2.firstY;

	player2F.xPos = player2F.firstX;
	player2F.yPos = player2F.firstY;

	map.resetBoard();
}

int main(int argc, char**argv)
{
	srand(time(NULL));
	std::map<std::string, int> ranking;
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	uti::hideCursor(console);

	int lifes;
	bool paused = false;

	GameState actualState = GameState::SPLASH_SCREEN;
	char start;
	char aux;
	char aux2;
	std::string name;
	bool firstTime=true;
	bool stop=true;
	std::chrono::duration<double> frametime;
	float playTime = 0.f;
	
	std::fstream myFile;
	std::string auxName;
	int auxInt;

	int sleepValue = 80;

	bool keyboard[(int)InputKey::COUNT] =
	{};

	while (actualState != GameState::EXIT)
	{
		if (!paused)
		{
			keyboard[(int)InputKey::K_ESC] = GetAsyncKeyState(VK_ESCAPE);
			keyboard[(int)InputKey::K_LEFT] = GetAsyncKeyState(VK_LEFT);
			keyboard[(int)InputKey::K_RIGHT] = GetAsyncKeyState(VK_RIGHT);
			keyboard[(int)InputKey::K_UP] = GetAsyncKeyState(VK_UP);
			keyboard[(int)InputKey::K_DOWN] = GetAsyncKeyState(VK_DOWN);
			keyboard[(int)InputKey::K_A] = GetAsyncKeyState(0x41);
			keyboard[(int)InputKey::K_S] = GetAsyncKeyState(0x53);
			keyboard[(int)InputKey::K_D] = GetAsyncKeyState(0x44);
			keyboard[(int)InputKey::K_W] = GetAsyncKeyState(0x57);
		}
		if (GetAsyncKeyState(0x50))
		{
			if (actualState == GameState::PAUSE)
				actualState = GameState::GAME;

			else if (actualState == GameState::GAME)
				actualState = GameState::PAUSE;
		}
		if (keyboard[(int)InputKey::K_ESC])
		{
			if (actualState == GameState::RANKING)
				actualState = GameState::MAINMENU;
			else
				actualState = GameState::EXIT;
		}
		switch (actualState)
		{
		case GameState::SPLASH_SCREEN:
			uti::printWithColor(console, "------------------------", uti::Color::RED, true);
			uti::printWithColor(console, "******  *******  *******", uti::Color::CYAN, true);
			uti::printWithColor(console, "  *     *     *  *      ", uti::Color::CYAN, true);
			uti::printWithColor(console, "  *     *******  *   ***", uti::Color::CYAN, true);
			uti::printWithColor(console, "  *     *     *  *******", uti::Color::CYAN, true);
			uti::printWithColor(console, "------------------------", uti::Color::RED, true);
			

			Sleep(3000);
			actualState = GameState::MAINMENU; 
			break;

		case GameState::MAINMENU:
			system("cls");
			playTime = 0;
			stop = true;
			//UI
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			std::cout << "*-*-*MAIN MENU*-*-*" << std::endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
			uti::printWithColor(console, "1. Play", uti::Color::GREEN, true);
			uti::printWithColor(console, "2. Ranking", uti::Color::CYAN, true);
			uti::printWithColor(console, "0. Exit", uti::Color::RED, true);
			std::cin >> start;
			//inputs
			if (start == '0') {
				start = ' ';
				actualState = GameState::EXIT;
			}
			if (start == '1') {
				start = ' ';
				actualState = GameState::GAME;
			}
			if (start == '2') {
				start = ' ';
				actualState = GameState::RANKING;
			}
			break;
		case GameState::GAME:
			
			if (firstTime)
			{
				lifes = 3;
				firstTime = false;
				reset();
			}
			if (!paused)
			{
				//INPUTS
				auto frameStart = std::chrono::system_clock::now();
				if (keyboard[(int)InputKey::K_UP])
				{
					player.movePlayer(Movement::UP, map.map);
					playerF.movePlayerF(Movement::DOWN, map.map);
					
				}
				if (keyboard[(int)InputKey::K_DOWN])
				{
					player.movePlayer(Movement::DOWN, map.map);
					playerF.movePlayerF(Movement::UP, map.map);
					
				}
				if (keyboard[(int)InputKey::K_LEFT])
				{
					player.movePlayer(Movement::LEFT, map.map);
					playerF.movePlayerF(Movement::RIGHT, map.map);
					
				}
				if (keyboard[(int)InputKey::K_RIGHT])
				{
					player.movePlayer(Movement::RIGHT, map.map);
					playerF.movePlayerF(Movement::LEFT, map.map);
					
				}
				if (keyboard[(int)InputKey::K_W])
				{
					player2.movePlayer2(Movement::UP, map.map);
					player2F.movePlayer2F(Movement::DOWN, map.map);
					
				}
				if (keyboard[(int)InputKey::K_S])
				{
					player2.movePlayer2(Movement::DOWN, map.map);
					player2F.movePlayer2F(Movement::UP, map.map);
				}
				if (keyboard[(int)InputKey::K_A])
				{
					player2.movePlayer2(Movement::LEFT, map.map);
					player2F.movePlayer2F(Movement::RIGHT, map.map);
				}
				if (keyboard[(int)InputKey::K_D])
				{
					player2.movePlayer2(Movement::RIGHT, map.map);
					player2F.movePlayer2F(Movement::LEFT, map.map);
				}
				//uUPDATE
				if (player2.newGame) {
					player2.newGame = false;
					lifes--;
					player.xPos = player.firstX;
					player.yPos = player.firstY;
					playerF.xPos = playerF.firstX;
					playerF.yPos = playerF.firstY;
				}
				if(player2F.newGame) {
					player2F.newGame = false;
					lifes--;
					player.xPos = player.firstX;
					player.yPos = player.firstY;
					playerF.xPos = playerF.firstX;
					playerF.yPos = playerF.firstY;
				}

				if (lifes == 0)
				{
					std::cin.clear();
					system("cls");
					firstTime = true;
					std::cout << "ENTER YOUR NAME" << std::endl;;
					std::cin >> name;
					ranking.clear();
					ranking[name] = playTime;

					actualState = GameState::RANKING;
				}

				

				auto frameEnd = std::chrono::system_clock::now();
				frametime = frameEnd - frameStart;
				playTime += frametime.count();
				system("cls");
				//DRAW
				std::cout << "*-*-*PLAYING*-*-*" << std::endl;
				std::cout << "TIME : " <<trunc(playTime) << std::endl;
				map.updateBoard();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				std::cout << "LIFES: " << lifes << std::endl;
				//FRAME CONTROL
				Sleep(sleepValue);
			}
			break;
		case GameState::PAUSE:
		
				system("cls");
				std::cout << "PAUSED" << std::endl;
				std::cout << "TIME: " << playTime << std::endl;
				map.updateBoard();
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
				
				std::cout << "LIFES: " << lifes << std::endl;
				break;

		case GameState::RANKING:
		
			
			if (stop)
			{
				myFile.open("Ranking.txt");
				
				do
				{
					std::getline(myFile, auxName, '-');
					myFile >> auxInt;
					if (myFile.eof())
						break;
					ranking[auxName] = auxInt;
				} while (true);
				myFile.close();

				std::vector<std::pair<std::string, int>> sortedElements(ranking.begin(), ranking.end());
				std::sort(sortedElements.begin(), sortedElements.end(), [](std::pair<std::string, int > p1, std::pair<std::string, int> p2) {return p1.second > p2.second; });
				
				system("cls");
				std::cout << "*-*-*RANKING*-*-*" << std::endl;
				myFile.open("Ranking.txt", std::fstream::out | std::fstream::trunc);

				for (int i = 0; i < sortedElements.size(); i++)
				{
					myFile << sortedElements[i].first << "-" << sortedElements[i].second << std::endl;
					std::cout << sortedElements[i].first << "-" << sortedElements[i].second << std::endl;
					if (i >= 4)
						break;
						
				}
				myFile.close();
			}
			stop = false;

			break;
		case GameState::EXIT:

			break;
		}
	}
	return 0;
}

