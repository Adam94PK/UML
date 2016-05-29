#include "stdafx.h"
#include "ToSecondLvl.h"
#include "Player.h"
#include "GameplayManager.h"

void ToSecondLvl::setDescription()
{
	descriptionText.setString("Uda³o Ci siê przebrn¹æ przez pierwszy rok,\njeœli uda³o Ci siê zyskaæ 60pkt ECT\nwcisnij ENTER a przejdziesz na drugi rok studiow");
}

void ToSecondLvl::perform(Player & player)
{
	player.setLevel(&GameplayManager::get()->gameLvl2);
}
