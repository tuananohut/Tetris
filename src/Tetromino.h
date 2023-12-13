#pragma once
#include <vector>
#include <map>
#include "Position.h"
#include "Colors.h"

class Tetromino
{
public:
	Tetromino();
	
	void draw(sf::RenderWindow& window, int offsetX, int offsetY);

	void move(int rows, int columns);
	void rotate();
	void unRotate();

	std::vector<Position> getCellPosition();

	int id;
	std::map<int, std::vector<Position>> cells;

private:
	int m_CellSize;
	int m_RotationState;
	std::vector<sf::Color> m_Colors;

	int m_RowOffset;
	int m_ColumnOffset;
};