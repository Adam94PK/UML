#include "stdafx.h"
#include "Zagadnienia.h"
#include "Player.h"

void Zagadnienia::setDescription()
{
	descriptionText.setString("Prawie zaspales na kolosa z Zagadnien spolecznych\ni zawodowych informatyki. Ten dziwnie\n brzmiacy przedmiot to tak naprawde\npodstawy informatyki.");
}

void Zagadnienia::perform(Player & player)
{
	player.addEcts(10);
	player.addKnowledge(5);
}
