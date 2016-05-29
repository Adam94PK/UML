#include "stdafx.h"
#include "Field.h"

void Field::setDescription()
{
	descriptionText.setString("This field do nothing \n Yes, nothing");
}

void Field::init()
{
	if (!font.loadFromFile("resources/arial.ttf"))
	{
		std::cout << "nie udalo sie zaladowac fonta" << std::endl;
	}
	descriptionText.setFont(font);
	descriptionText.setCharacterSize(20);
	descriptionText.setPosition(850.f, 200.f);
	descriptionText.setColor(sf::Color::White);
	setDescription();
}

void Field::perform(Player &player) {

}

void Field::drawDescription(sf::RenderWindow & window)
{
	window.draw(descriptionText);
}
