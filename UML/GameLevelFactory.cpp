#include "stdafx.h"
#include "GameLevelFactory.h"
#include "GameLevel.h"
#include "FieldsHeaders.h"

GameLevel GameLevelFactory::getLvl_1()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_1_SIZE);
	gameLvl.size = LEVEL_1_SIZE;
	for (int i = 0; i < LEVEL_1_SIZE; i++)
	{
		if (i == 2 || i == 34)
		{
			shared_ptr<Field> pointer(new Beer());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 3)
		{
			shared_ptr<Field> pointer(new WDP());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 6)
		{
			shared_ptr<Field> pointer(new Zagadnienia());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 7)
		{
			shared_ptr<Field> pointer(new Metodyka());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 8)
		{
			shared_ptr<Field> pointer(new Weekend());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 9)
		{
			shared_ptr<Field> pointer(new WF());
			pointer->init();
			gameLvl.fields.push_back(pointer);
		}
		else if (i == 10)
		{
			shared_ptr<Field> pointer(new PEiTC_lab());
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
