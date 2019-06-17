#include "Utilities.h"
uti::Vec2::Vec2() : x(0), y(0) {}

uti::Vec2::Vec2(int _x, int _y) : x(_x), y(_y) {}

uti::Vec2 uti::Vec2::operator+(const Vec2 & v)
{
	return Vec2(this->x + v.x, this->y + v.y);
}

uti::Vec2 & uti::Vec2::operator+=(const Vec2 & v)
{
	this->x += v.x;
	this->y += v.y;
	return *this;
}

void uti::hideCursor(HANDLE & myHandleTemp)
{
	CONSOLE_CURSOR_INFO cmdCursor; //cursor de la cmd
	cmdCursor.dwSize = 10; //tamany petit
	cmdCursor.bVisible = false; // el cursor no es veu
	SetConsoleCursorInfo(myHandleTemp, &cmdCursor);
}

void uti::selectColorAndSetIt(HANDLE & myCursor, uti::Color tmp_c) //conjunt de colors
{
	switch (tmp_c)
	{
	case uti::Color::BLUE://blau
		SetConsoleTextAttribute(myCursor, FOREGROUND_BLUE
			| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case uti::Color::RED://vermell
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case uti::Color::GREEN: //verd
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	case uti::Color::YELLOW://groc
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		break;
	case uti::Color::PURPLE://lila
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		break;
	case uti::Color::CYAN://blau fluix
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		break;
	default://blanc
		SetConsoleTextAttribute(myCursor,
			FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	}
}

void uti::printWithColor(HANDLE& h, std::string s, uti::Color c, bool endl)
{
	uti::selectColorAndSetIt(h, c);
	std::cout << s;
	if (endl) std::cout << std::endl;

	uti::selectColorAndSetIt(h, Color::WHITE);
}
