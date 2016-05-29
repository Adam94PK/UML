#include "stdafx.h"
#include "GameplayManager.h"
#include "Gameplay.h"

Gameplay * GameplayManager::get()
{
	if (gameplay == nullptr)
	{
		gameplay = new Gameplay();
	}
	return gameplay;
}

bool GameplayManager::release()
{
	if (gameplay == nullptr)
	{
		return false;
	}
	delete gameplay;
	return true;
}

Gameplay * GameplayManager::gameplay = nullptr;