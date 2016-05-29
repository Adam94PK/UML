#include "stdafx.h"
#include "SSPK.h"
#include "Player.h"

void SSPK::setDescription()
{
	descriptionText.setString("Dolaczasz do Samorzadu. Liczba Twoich\nznajomosci diamtetralnie rosnie!");
}

void SSPK::perform(Player & player)
{
	player.addConnectoins(7);
}
