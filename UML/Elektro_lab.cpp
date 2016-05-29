#include "stdafx.h"
#include "Elektro_lab.h"
#include "Player.h"

void Elektro_lab::setDescription()
{
	descriptionText.setString("Przychodzisz z gotowcami. Jestes taki sprytny jak ostatnie 7 rocznikow!");
}

void Elektro_lab::perform(Player & player)
{
	player.addFlair(5);
}
