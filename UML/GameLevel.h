#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

using namespace std;

class GameLevel
{
	friend GameLevelFactory;
	bool init(vector<shared_ptr<Field>> &v, const string & file);
	bool loadSprite(const string & file);
	int size;
	std::vector<shared_ptr<Field>> fields;
	sf::Texture level_texture;
	sf::Sprite level_spirte;
public:
	bool draw(sf::RenderWindow & window);
	Field & operator[](int i);
	int getSize() const;
};

