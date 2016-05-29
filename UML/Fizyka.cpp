#include "stdafx.h"
#include "Fizyka.h"
#include "Player.h"

void Fizyka::setDescription()
{
	descriptionText.setString("Pan Zachu pozwolil Ci zdawac egzamin\npo raz milionowy. W koncu\nCi sie udalo!");
}

void Fizyka::perform(Player & player)
{
	player.addEcts(4);
	player.addFlair(4);
}
