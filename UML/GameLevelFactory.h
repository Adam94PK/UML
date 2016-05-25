#pragma once
#include "LibsAndDeclarations.h"

class GameLevelFactory
{
public:
	static const int LEVEL_1_SIZE = 36;
	static const int LEVEL_2_SIZE = 24;
	static const int LEVEL_3_SIZE = 16;
	static GameLevel getLvl_1();
	static GameLevel getLvl_2();
	static GameLevel getLvl_3();
};

