#include "Game.h"
#include <iostream>
#include <string>

#include <Windows.h>

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	::ShowWindow(::GetConsoleWindow(), SW_HIDE);

	sf::ContextSettings settings;
	settings.antialiasingLevel = 10;
	sf::RenderWindow window(sf::VideoMode(500, 620), "Tetris", sf::Style::Default, settings);
	window.setFramerateLimit(60);

	Game game = Game();

	sf::Clock clock;
	sf::Time deltaTime;
	sf::Time elapsedTime = sf::Time::Zero;

	const float interval = 0.5f;

	sf::Font font;

	sf::Text text_score;
	text_score.setFont(font);
	text_score.setString("Score");
	text_score.setOrigin(19, 19);
	text_score.setPosition(365, 15);
	text_score.setCharacterSize(38);

	sf::Text text_next;
	text_next.setFont(font);
	text_next.setString("Next");
	text_next.setOrigin(19, 19);
	text_next.setPosition(370, 175);
	text_next.setCharacterSize(38);

	sf::Text text_gameOver;
	text_gameOver.setFont(font);
	text_gameOver.setString("GAME OVER!");
	text_gameOver.setOrigin(14, 14);
	text_gameOver.setPosition(330, 450);
	text_gameOver.setCharacterSize(28);

	sf::RectangleShape rect_score(sf::Vector2f(170, 60));
	rect_score.setPosition(320, 55);
	rect_score.setFillColor(sf::Color(48, 52, 90));

	sf::RectangleShape rect_next(sf::Vector2f(170, 180));
	rect_next.setPosition(320, 215);
	rect_next.setFillColor(sf::Color(48, 52, 90));

	sf::Text score;
	score.setFont(font);
	score.setCharacterSize(38);
	sf::FloatRect rectBounds = rect_score.getLocalBounds();
	score.setOrigin(rectBounds.width / 2, rectBounds.height / 2);
	
	sf::Vector2f scorePosition = rect_score.getPosition() + sf::Vector2f(rectBounds.width / 2, rectBounds.height / 2);

	if(!font.loadFromFile("font/opensans.ttf"))
	{
		std::cout << "Could not found the file!" << std::endl;
	}


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
		
		scorePosition.x = rect_score.getPosition().x + rectBounds.width / 2;
		score.setPosition(scorePosition);
		
		score.setString(std::to_string(game.score));

		window.draw(rect_score);
		window.draw(rect_next);
		window.draw(text_score);
		window.draw(score);
		window.draw(text_next);
		game.draw(window);
		
		if (game.isGameOver)
		{
			window.draw(text_gameOver);
		}


		window.display();
	}
	
	return 0;
}