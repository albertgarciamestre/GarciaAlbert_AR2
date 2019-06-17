#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>
#include <algorithm>

namespace uti {
	enum class Color { BLUE, CYAN, RED, GREEN, YELLOW, PURPLE, WHITE };
	enum class State { MENU, PLAY, SCORE, RANKING };
	enum class InputKeys { K_ESC, K_LEFT, K_RIGHT, K_PLAY, K_RANKING, K_MENU, NUM_KEYS };

	void hideCursor(HANDLE&);

	struct Vec2 {

	public:
		int x, y;
		Vec2();
		Vec2(int, int);
		uti::Vec2 operator+(const Vec2&);
		uti::Vec2& operator+=(const Vec2&);
	};

	void selectColorAndSetIt(HANDLE &, uti::Color); //seleccionem el color que vulguem del enum
	void printWithColor(HANDLE &, std::string, uti::Color, bool);
}

