#pragma once
#include "Field.h"

class Boyfriend : public Field
{
	void setDescription();
public:
	void perform(Player &player);
};

