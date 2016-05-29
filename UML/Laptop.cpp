#include "stdafx.h"
#include "Laptop.h"
#include "Player.h"

void Laptop::setDescription()
{
	descriptionText.setString("Zepsul Ci sie laptop.\nTwoj swiat legl w gruzach.\nMusisz znowu wyjsc do ludzi :(");
}

void Laptop::perform(Player & player)
{
	player.addKnowledge(-10);
	player.addFlair(-5);
	player.addConnectoins(7);
}
