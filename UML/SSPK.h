#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"
class SSPK : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

