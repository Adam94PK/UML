#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

class KNIT : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

