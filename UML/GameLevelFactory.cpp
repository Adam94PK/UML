#include "stdafx.h"
#include "GameLevelFactory.h"
#include "GameLevel.h"

GameLevel GameLevelFactory::getLvl_1()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_1_SIZE);
	gameLvl.size = LEVEL_1_SIZE;
	for (int i = 0; i < LEVEL_1_SIZE; i++)
		gameLvl.fields.emplace_back(std::make_shared<Field>());

	gameLvl.loadSprite("game_board.jpg");
	return move(gameLvl);
}

GameLevel GameLevelFactory::getLvl_2()
{
	// TODO: insert return statement here
	return GameLevel();
}

GameLevel GameLevelFactory::getLvl_3()
{
	// TODO: insert return statement here
	return GameLevel();
}
