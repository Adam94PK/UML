#pragma once
#include "LibsAndDeclarations.h"

class Field
{
protected:
	sf::Text descriptionText;
	sf::Font font;
	virtual void setDescription();
public:
	virtual void init();
	virtual void perform(Player &player);
	virtual void drawDescription(sf::RenderWindow & window);
};

