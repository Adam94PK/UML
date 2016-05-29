#pragma once
#include "Field.h"

class WF : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

