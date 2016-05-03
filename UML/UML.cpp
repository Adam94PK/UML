// UML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "classes.h"
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	std::string names[2]={ "Adam", "Kuba" };
	Game gra(2, names);
	gra.start();
	system("PAUSE");
	return 0;
}