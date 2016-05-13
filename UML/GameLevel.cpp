#include "stdafx.h"
#include "GameLevel.h"


GameLevel::GameLevel()
{
}


GameLevel::~GameLevel()
{
}

Field & const GameLevel::operator[](int i)
{
	if (i < size)
		return fields[i];
}
