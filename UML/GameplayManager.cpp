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

Gameplay * GameplayManager::gameplay = nullptr;