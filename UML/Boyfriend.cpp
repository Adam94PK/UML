#include "stdafx.h"
#include "Boyfriend.h"
#include "Player.h"

void Boyfriend::setDescription()
{
	descriptionText.setString("Zakochales/las sie! Niestety milosc oglupia...");
}

void Boyfriend::perform(Player & player)
{
	player.addKnowledge(-10);
	player.addConnectoins(2);
}
