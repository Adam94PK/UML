#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Met_progr_egz : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

