#include "Game.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(300, 600), "Tetris", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Game game = Game();

	sf::Clock clock;
	sf::Time deltaTime;
	sf::Time elapsedTime = sf::Time::Zero;

	const float interval = 0.5f;

	while(window.isOpen())
	{
		game.userInput(window);
		
		deltaTime = clock.restart();
		float dtSeconds = deltaTime.asSeconds();

		elapsedTime += deltaTime;

		if(elapsedTime.asSeconds() > interval)
		{
			game.m_Drop();

			elapsedTime = sf::Time::Zero;
		}
		
		window.clear(sf::Color::Black);

		game.draw(window);

		window.display();
	}
	
	return 0;
}