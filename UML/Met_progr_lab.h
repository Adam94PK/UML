#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class Met_progr_lab : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

