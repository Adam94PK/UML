#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Dyskretna : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

