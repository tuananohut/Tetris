#include "Game.h"

Game::Game()
{
	this->grid = Grid();

	this->m_Tetrominos = getTetrominos();
	
	this->m_CurrentTetromino = getRandomTetromino();
	this->m_NextTetromino = getRandomTetromino();

	this->isGameOver = false;
}

Tetromino Game::getRandomTetromino()
{
	if(this->m_Tetrominos.empty())
	{
		this->m_Tetrominos = getTetrominos();
	}
	
	int randIndex = std::rand() % this->m_Tetrominos.size();

	Tetromino tetromino = this->m_Tetrominos[randIndex];
	
	this->m_Tetrominos.erase(this->m_Tetrominos.begin() + randIndex);

	return tetromino;
}

std::vector<Tetromino> Game::getTetrominos()
{
	return { ITetromino(), JTetromino(), LTetromino(), OTetromino(), STetromino(), TTetromino(), ZTetromino() };
}

void Game::draw(sf::RenderWindow& window)
{
	this->grid.draw(window);
	this->m_CurrentTetromino.draw(window);
}

void Game::userInput(sf::RenderWindow& window)
{
	sf::Event event;
	while (window.pollEvent(event) )
	{
		if (event.type == sf::Event::Closed)
		{
			window.close();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::R && this->isGameOver)
		{
			reset();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space && !this->isGameOver)
		{
			m_Rotate();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Left && !this->isGameOver)
		{
			m_MoveLeft();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Right && !this->isGameOver)
		{
			m_MoveRight();
		}

		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Down && !this->isGameOver)
		{
			m_Drop();
		}
	}
	
}

void Game::reset()
{
	this->isGameOver = false;
	this->grid.init();
	this->m_Tetrominos = getTetrominos();
	this->m_CurrentTetromino = getRandomTetromino();
	this->m_NextTetromino = getRandomTetromino();
}


void Game::m_MoveLeft()
{
	this->m_CurrentTetromino.move(0, -1);
	if (m_IsTetrominoOut() || !m_IsTetrominoFit())
	{
		this->m_CurrentTetromino.move(0, 1);
	}
}

void Game::m_MoveRight()
{
	this->m_CurrentTetromino.move(0, 1);
	if (m_IsTetrominoOut() || !m_IsTetrominoFit())
	{
		this->m_CurrentTetromino.move(0, -1);
	}
}

void Game::m_Drop()
{
	this->m_CurrentTetromino.move(1, 0);
	if (m_IsTetrominoOut() || !m_IsTetrominoFit())
	{
		this->m_CurrentTetromino.move(-1, 0);
		m_LockTetromino();
	}
}

void Game::m_LockTetromino()
{
	std::vector<Position> tiles = this->m_CurrentTetromino.getCellPosition();

	for(auto item: tiles)
	{
		this->grid.grid[item.row][item.column] = this->m_CurrentTetromino.id;
	}

	this->m_CurrentTetromino = this->m_NextTetromino;
	if(!m_IsTetrominoFit())
	{
		isGameOver = true;
	}
	else
	{
		this->m_NextTetromino = getRandomTetromino();
		grid.clearFullRows();
	}
}

void Game::m_Rotate()
{
	this->m_CurrentTetromino.rotate();
	if (m_IsTetrominoOut() || !m_IsTetrominoFit())
	{
		this->m_CurrentTetromino.unRotate();
	}
}

bool Game::m_IsTetrominoOut()
{
	std::vector<Position> tiles = this->m_CurrentTetromino.getCellPosition();

	for(auto item: tiles)
	{
		if(this->grid.isCellOut(item.row, item.column))
		{
			return true;
		}
	}

	return false;
}

bool Game::m_IsTetrominoFit()
{
	std::vector<Position> tiles = this->m_CurrentTetromino.getCellPosition();

	for(auto item: tiles)
	{
		if(grid.isCellEmpty(item.row, item.column) == false)
		{
			return false;
		}
	}
	
	return true;
}