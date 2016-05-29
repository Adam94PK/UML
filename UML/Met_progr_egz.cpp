#include "stdafx.h"
#include "Met_progr_egz.h"
#include "Player.h"

void Met_progr_egz::setDescription()
{
	descriptionText.setString("Dzisiaj egzamin z Metod Programowania!\nJestes sprytny i madry, wiec dostajesz ECTSy!");
}

void Met_progr_egz::perform(Player & player)
{
	player.addEcts(4);
	player.addFlair(5);
	player.addKnowledge(8);
}
