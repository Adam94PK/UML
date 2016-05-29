#include "stdafx.h"
#include "LibsAndDeclarations.h"
#include "GameState.h"
#include "Gameplay.h"
#include "GameplayManager.h"	

int main()
{
	static const int game_width = 1300;
	static const int game_height = 800;

	sf::RenderWindow window(sf::VideoMode(game_width, game_height, 32), "PK-GAME", sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	std::string names [2] = { "Gracz 1", "Gracz 2" };
	Gameplay *gameplay = GameplayManager::get();
	gameplay->init(2, names);
	GameState * gameState(gameplay);
	gameState->init();
	sf::Clock clock;

	while (window.isOpen()) 
	{
		//EVENT
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
					window.close();
			}
		}

		//UPDATE
		{
			float delta_time = clock.restart().asSeconds();
			gameState->update(delta_time);
		}
		//DRAW
		{
			gameState->draw(window);
			window.display();
		}

	}
	GameplayManager::release();
	return 0;
}