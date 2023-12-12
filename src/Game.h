#pragma once

#include "Grid.h"
#include "Tetrominos.cpp"

class Game
{
public:
	Game();

	Grid grid;

	std::vector<Tetromino> getTetrominos();
	Tetromino getRandomTetromino();

	void draw(sf::RenderWindow& window);
	
	void userInput(sf::RenderWindow& window);
	
	void m_Drop();

	void reset();
	bool isGameOver;

private:
	std::vector<Tetromino> m_Tetrominos;

	Tetromino m_CurrentTetromino;
	Tetromino m_NextTetromino;

	void m_MoveLeft();
	void m_MoveRight();
	void m_Rotate();
	void m_LockTetromino();
	
	bool m_IsTetrominoFit();
	bool m_IsTetrominoOut();
};