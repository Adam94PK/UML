#include "stdafx.h"
#include "ToSecondLvl.h"
#include "Player.h"
#include "GameplayManager.h"

void ToSecondLvl::setDescription()
{
	descriptionText.setString("Uda�o Ci si� przebrn�� przez pierwszy rok,\nje�li uda�o Ci si� zyska� 60pkt ECT\nwcisnij ENTER a przejdziesz na drugi rok studiow");
}

void ToSecondLvl::perform(Player & player)
{
	player.setLevel(&GameplayManager::get()->gameLvl2);
}
