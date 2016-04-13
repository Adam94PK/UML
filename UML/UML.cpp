// UML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "classes.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	std::string names[2]={ "adan", "kuba" };
	Game gra2(2, names);
	system("PAUSE");
	return 0;
}