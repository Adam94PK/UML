#include "stdafx.h"
#include "Rajd.h"
#include "Player.h"

void Rajd::setDescription()
{
	descriptionText.setString("RAJD CIE ZNISZCZYL.");
}

void Rajd::perform(Player & player)
{
	player.addHangover(30);
	player.addConnectoins(15);
}
