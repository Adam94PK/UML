#include "stdafx.h"
#include "PEiTC_lab.h"
#include "Player.h"

void PEiTC_lab::setDescription()
{
	descriptionText.setString("PEiTC takie trudne. Ale laborki z dr Szromba\nnie takie straszne! Duzo wiedzy!");
}

void PEiTC_lab::perform(Player & player)
{
	player.addKnowledge(10);
}
