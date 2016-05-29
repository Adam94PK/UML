#include "stdafx.h"
#include "Analiza.h"
#include "Player.h"

void Analiza::setDescription()
{
	descriptionText.setCharacterSize(60);
	descriptionText.setString("Tak");
}

void Analiza::perform(Player & player)
{
	player.addHangover(2);
	player.addEcts(10);
	player.addFlair(3);
}
