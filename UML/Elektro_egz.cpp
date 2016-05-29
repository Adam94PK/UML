#include "stdafx.h"
#include "Elektro_egz.h"
#include "Player.h"

void Elektro_egz::setDescription()
{
	descriptionText.setString("Masz znajomych, dlatego zdales egzamin");
}

void Elektro_egz::perform(Player & player)
{
	player.addConnectoins(5);
	player.addEcts(2);
}
