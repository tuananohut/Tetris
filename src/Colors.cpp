#include "Colors.h"

const sf::Color background = sf::Color(19, 58, 58);
const sf::Color cyan = sf::Color::Cyan;
const sf::Color white = sf::Color::White;
const sf::Color blue = sf::Color::Blue;
const sf::Color magenta = sf::Color::Magenta;
const sf::Color yellow = sf::Color::Yellow;
const sf::Color red = sf::Color::Red;
const sf::Color green = sf::Color::Green;

std::vector<sf::Color> getCellColors()
{
	return { background, cyan, white, blue, magenta, yellow, red, green };
}