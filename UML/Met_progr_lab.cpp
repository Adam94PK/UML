#include "stdafx.h"
#include "Met_progr_lab.h"
#include "Player.h"

void Met_progr_lab::setDescription()
{
	descriptionText.setString("Masz laborski z mgr Nowakowskim.\nW koncu sie czegos uczysz!\nA czasem skoczysz na piknik w ramach zajec...");
}

void Met_progr_lab::perform(Player & player)
{
	player.addKnowledge(10);
	player.addHangover(2);
	player.addConnectoins(5);
}
