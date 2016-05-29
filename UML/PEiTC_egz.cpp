#include "stdafx.h"
#include "PEiTC_egz.h"
#include "Player.h"

void PEiTC_egz::setDescription()
{
	descriptionText.setString("Jest ciezko. Jest bardzo ciezko.\nUczysz sie i uczysz, i zdajesz przez przypadek");
}

void PEiTC_egz::perform(Player & player)
{
	player.addEcts(5);
}
