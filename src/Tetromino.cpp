#include "Tetromino.h"

Tetromino::Tetromino()
{
	this->m_CellSize = 30;
	this->m_RotationState = 0;
	this->m_Colors = getCellColors();
	this->m_RowOffset = 0;
	this->m_ColumnOffset = 0;
}

void Tetromino::draw(sf::RenderWindow& window, int offsetX, int offsetY)
{
	std::vector<Position> tiles = getCellPosition();

	for(Position item: tiles)
	{
		sf::RectangleShape tetromino(sf::Vector2f(m_CellSize - 1.f, m_CellSize - 1.f));
		tetromino.setPosition(item.column * m_CellSize + offsetX, item.row * m_CellSize + offsetY);
		tetromino.setFillColor(m_Colors[id]);
		window.draw(tetromino);
	}
}

void Tetromino::move(int rows, int columns)
{
	this->m_RowOffset += rows;
	this->m_ColumnOffset += columns;

}

void Tetromino::rotate()
{
	this->m_RotationState += 1;
	this->m_RotationState %= 4;
}

void Tetromino::unRotate()
{
	this->m_RotationState -= 1;

	if(this->m_RotationState == -1)
	{
		this->m_RotationState = cells.size() - 1;
	}


}

std::vector<Position> Tetromino::getCellPosition()
{
	std::vector<Position> tiles = cells[this->m_RotationState];
	std::vector<Position> movedTiles;
	
	for(auto item: tiles)
	{
		Position newPos = Position(item.row + this->m_RowOffset, item.column + this->m_ColumnOffset);
		movedTiles.push_back(newPos);
	}

	return movedTiles;
}