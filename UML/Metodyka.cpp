#include "stdafx.h"
#include "Metodyka.h"
#include "Player.h"

void Metodyka::setDescription()
{
	descriptionText.setString("Metodyka. Jestes mistrzem studiowania,\nwiec bez bolu dostajesz ECTSy.");
}

void Metodyka::perform(Player & player)
{
	player.addEcts(1);
}


