#include "stdafx.h"
#include "Dyskretna.h"
#include "Player.h"

void Dyskretna::setDescription()
{
	descriptionText.setString("Prowadzacy znowu spoznil sie 50min\nna zajecia. Masz do niego tyle\nsamo szacunku, wiec poszedles\nz cala ekipa na piwo.");
}

void Dyskretna::perform(Player & player)
{
	player.addConnectoins(10);
	player.addHangover(7);
}
