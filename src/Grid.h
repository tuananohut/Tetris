#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

class Grid
{
public:
	Grid();

	void init();
	void draw(sf::RenderWindow& window);
	
	bool isCellOut(int row, int column);
	bool isCellEmpty(int row, int column);
	bool isRowFull(int row);

	void clearRow(int row);
	void moveRowDown(int row, int numRows);
	int clearFullRows();

	int grid[20][10];

private:
	int m_Rows;
	int m_Cols;
	int cellSize;
	std::vector<sf::Color> m_Colors;
};