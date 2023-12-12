#include <iostream>
#include "Grid.h"
#include "Colors.h"

Grid::Grid()
{
	this->m_Rows = 20;
	this->m_Cols = 10;
	this->cellSize = 30;
	this->init();
	this->m_Colors = getCellColors();
}

void Grid::init()
{
	for(int row = 0; row < this->m_Rows; row++)
	{
		for(int column = 0; column < this->m_Cols; column++)
		{
			grid[row][column] = 0;
		}
	}
}


void Grid::draw(sf::RenderWindow& window)
{
	for (int row = 0; row < this->m_Rows; row++)
	{
		for (int column = 0; column < this->m_Cols; column++)
		{
			int cellValue = grid[row][column];
			sf::RectangleShape rectangle(sf::Vector2f(cellSize - 1.f, cellSize - 1.f));
			rectangle.setFillColor(m_Colors[cellValue]);
			rectangle.setPosition((rectangle.getPosition().x + column) * 30 + 1, (rectangle.getPosition().y + row) * 30 + 1);
			window.draw(rectangle);
		}
	}
}

bool Grid::isCellOut(int row, int column)
{
	if(row >= 0 && row < this->m_Rows && column >= 0 && column < this->m_Cols)
	{
		return false;
	}

	return true;
}

bool Grid::isCellEmpty(int row, int column)
{
	if(grid[row][column] == 0)
	{
		return true;
	}

	return false;
}

bool Grid::isRowFull(int row)
{
	for(int column = 0; column < this->m_Cols; column++)
	{
		if(grid[row][column] == 0)
		{
			return false;
		}
	}

	return true;
}

void Grid::clearRow(int row)
{
	for (int column = 0; column < this->m_Cols; column++)
	{
		grid[row][column] = 0;
	}
}

void Grid::moveRowDown(int row, int numRows)
{
	for (int column = 0; column < this->m_Cols; column++)
	{
		grid[row + numRows][column] = grid[row][column];
		grid[row][column] = 0;
	}
}

int Grid::clearFullRows()
{
	int completed = 0; 

	for(int row = this->m_Rows - 1; row >= 0; row--)
	{
		if (isRowFull(row))
		{
			clearRow(row);
			completed += 1;
		}
		else if(completed > 0)
		{
			moveRowDown(row, completed);
		}
	}
	return completed;
}