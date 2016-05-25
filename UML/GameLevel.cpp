#include "stdafx.h"
#include "GameLevel.h"

bool GameLevel::init(vector<shared_ptr<Field>>& v, const string & file)
{
	size = v.size();
	fields = move(v);
	if (!level_texture.loadFromFile(file))
	{
		std::cout << "could not load texture, from file " << file << endl;
	}
	level_spirte.setTexture(level_texture);
	return false;
}

bool GameLevel::loadSprite(const string & file)
{
	if (!level_texture.loadFromFile(file))
	{
		std::cout << "could not load texture, from file " << file << endl;
		return false;
	}
	level_spirte.setTexture(level_texture);
	return true;
}

bool GameLevel::draw(sf::RenderWindow & window)
{
	window.draw(level_spirte);
	return true;
}

Field & GameLevel::operator[](int i)
{
	if (i < size)
		return *fields[i];
}

int GameLevel::getSize() const
{
	return size;
}
