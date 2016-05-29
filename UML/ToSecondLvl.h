#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class ToSecondLvl : public Field
{
	void setDescription();
public:
	void perform(Player & player);
};

