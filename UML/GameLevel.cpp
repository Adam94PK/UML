#include "stdafx.h"
#include "GameLevel.h"

/*bool GameLevel::init(vector<shared_ptr<Field>>& v, const string & file)
{
	size = v.size();
	fields = move(v);
	if (!level_texture.loadFromFile(file))
	{
		std::cout << "could not load texture, from file " << file << endl;
	}
	level_spirte.setTexture(level_texture);
	return false;
}*/

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

GameLevel::GameLevel(GameLevel && source) : GameLevel()
{
	this->swap(source);
}

GameLevel & GameLevel::operator=(GameLevel source)
{
	this->swap(source);
	return *this;
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

void GameLevel::swap(GameLevel & source)
{
	std::swap(fields, source.fields);
	std::swap(level_texture, source.level_texture);
	std::swap(level_spirte, source.level_spirte);
	level_spirte.setTexture(level_texture);
	std::swap(size, source.size);
}
