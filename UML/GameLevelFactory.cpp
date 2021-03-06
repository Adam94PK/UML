#include "stdafx.h"
#include "GameLevelFactory.h"
#include "GameLevel.h"
#include "FieldsHeaders.h"

inline void GameLevelFactory::makeField(Field *whichField, GameLevel &gamelvl)
{
	shared_ptr<Field> pointer(whichField);
	pointer->init();
	gamelvl.fields.push_back(pointer);
}

GameLevel GameLevelFactory::getLvl_1()
{
	GameLevel gameLvl;
	gameLvl.fields.reserve(LEVEL_1_SIZE);
	gameLvl.size = LEVEL_1_SIZE;
	for (int i = 0; i < LEVEL_1_SIZE; i++)
	{
		if (i == 2 || i == 34)
		{
			makeField(new Beer(), gameLvl);
		}
		else if (i == 3)
		{
			makeField(new WDP(), gameLvl);
		}
		else if (i == 6)
		{
			makeField(new Zagadnienia(), gameLvl);
		}
		else if (i == 7)
		{
			makeField(new Metodyka(), gameLvl);
		}
		else if (i == 8)
		{
			makeField(new Weekend(), gameLvl);
		}
		else if (i == 9)
		{
			makeField(new WF(), gameLvl);
		}
		else if (i == 10)
		{
			makeField(new PEiTC_lab(), gameLvl);
		}
		else if (i == 12)
		{
			makeField(new SSPK(), gameLvl);
		}
		else if (i == 13)
		{
			makeField(new PEiTC_egz(), gameLvl);
		}
		else if (i == 15)
		{
			makeField(new Elektro_lab(), gameLvl);
		}
		else if (i == 16)
		{
			makeField(new Elektro_egz(), gameLvl);
		}
		else if (i == 18)
		{
			makeField(new ToSecondLvl(), gameLvl);
		}
		else if (i == 20)
		{
			makeField(new Met_progr_egz(), gameLvl);
		}
		else if (i == 23)
		{
			makeField(new Rajd(), gameLvl);
		}
		else if (i == 24)
		{
			makeField(new Met_progr_lab(), gameLvl);
		}
		else if (i == 26)
		{
			makeField(new Dyskretna(), gameLvl);
		}
		else if (i == 27)
		{
			makeField(new Laptop(), gameLvl);
		}
		else if (i == 28)
		{
			makeField(new Fizyka(), gameLvl);
		}
		else if (i == 29)
		{
			makeField(new Boyfriend(), gameLvl);
		}
		else if (i == 31)
		{
			makeField(new KNIT(), gameLvl);
		}
		else if (i == 33)
		{
			makeField(new Analiza(), gameLvl);
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