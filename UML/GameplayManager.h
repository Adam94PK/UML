#pragma once
#include "LibsAndDeclarations.h"
#include "Gameplay.h"

class GameplayManager
{
	static Gameplay * gameplay;
public:
	static Gameplay * get();
};
