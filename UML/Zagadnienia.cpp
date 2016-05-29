#include "stdafx.h"
#include "Zagadnienia.h"
#include "Player.h"

void Zagadnienia::setDescription()
{
	descriptionText.setString("Prawie zaspales na egzamin z Zagadnien zawodowych w informatyce. \Ten dziwnie brzmiacy przedmiot to tak naprawde podstawy informatyki\n aby zdac rzuc koscia");
}

void Zagadnienia::perform(Player & player)
{
	player.addEcts(10);
	player.addKnowledge(5);
}
