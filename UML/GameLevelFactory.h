#pragma once
#include "LibsAndDeclarations.h"

class GameLevelFactory
{
public:
	static const int LEVEL_1_SIZE = 36;
	static const int LEVEL_2_SIZE = 28;
	static const int LEVEL_3_SIZE = 20;
	static GameLevel getLvl_1();
	static GameLevel getLvl_2();
	static GameLevel getLvl_3();
};

