#include "stdafx.h"
#include "GameLevelFactory.h"
#include "GameLevel.h"
#include "Beer.h"

GameLevel GameLevelFactory::getLvl_1()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_1_SIZE);
	gameLvl.size = LEVEL_1_SIZE;
	for (int i = 0; i < LEVEL_1_SIZE; i++)
	{
		if (i == 2)
		{
			shared_ptr<Field> pointer(new Beer());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else
		{
			gameLvl.fields.emplace_back(make_shared<Field>());
			gameLvl.fields[i]->init();
		}
	}
	gameLvl.loadSprite("level1.png");
	return move(gameLvl);
}

GameLevel GameLevelFactory::getLvl_2()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_2_SIZE);
	gameLvl.size = LEVEL_2_SIZE;
	for (int i = 0; i < LEVEL_2_SIZE; i++)
		gameLvl.fields.emplace_back(make_shared<Field>());
	gameLvl.loadSprite("level2.png");
	gameLvl.level_spirte.setPosition(80., 80.);
	return move(gameLvl);
}

GameLevel GameLevelFactory::getLvl_3()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_3_SIZE);
	gameLvl.size = LEVEL_3_SIZE;
	for (int i = 0; i < LEVEL_3_SIZE; i++)
		gameLvl.fields.emplace_back(make_shared<Field>());
	gameLvl.loadSprite("level3.png");
	gameLvl.level_spirte.setPosition(160., 160.);
	return move(gameLvl);
}
