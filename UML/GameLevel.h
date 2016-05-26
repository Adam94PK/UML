#pragma once
#include "LibsAndDeclarations.h"
#include "Field.h"

using namespace std;

class GameLevel
{
	friend GameLevelFactory;
	//bool init(vector<shared_ptr<Field>> &v, const string & file);
	bool loadSprite(const string & file);
	int size;
	std::vector<shared_ptr<Field>> fields;
	sf::Sprite level_spirte;
public:
	GameLevel() = default;
	GameLevel(GameLevel &) = delete;
	GameLevel(GameLevel && source);
	GameLevel & operator=(GameLevel source);
	bool draw(sf::RenderWindow & window);
	Field & operator[](int i);
	int getSize() const;
	void swap(GameLevel & source);
	sf::Texture level_texture;
	sf::Vector2f getSpritePosition();
};

