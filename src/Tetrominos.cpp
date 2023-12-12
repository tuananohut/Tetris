#include "Tetromino.h"
#include "Position.h"

class LTetromino: public Tetromino
{
public:
	LTetromino()
	{
		id = 1;
		cells[0] = { Position(0, 2), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 0) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}
};


class JTetromino : public Tetromino
{
public:
	JTetromino()
	{
		id = 2;
		cells[0] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 0), Position(2, 1) };
		move(0, 3);
	}
};


class ITetromino : public Tetromino
{
public:
	ITetromino()
	{
		id = 3;
		cells[0] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3) };
		cells[1] = { Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2) };
		cells[2] = { Position(2, 0), Position(2, 1), Position(2, 2), Position(2, 3) };
		cells[3] = { Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1) };
		move(-1, 3);
	}
};


class OTetromino : public Tetromino
{
public:
	OTetromino()
	{
		id = 4;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[2] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		cells[3] = { Position(0, 0), Position(0, 1), Position(1, 0), Position(1, 1) };
		move(0, 3);
	}
};


class STetromino : public Tetromino
{
public:
	STetromino()
	{
		id = 5;
		cells[0] = { Position(0, 1), Position(0, 2), Position(1, 0), Position(1, 1) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 2) };
		cells[2] = { Position(1, 1), Position(1, 2), Position(2, 0), Position(2, 1) };
		cells[3] = { Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}
};


class ZTetromino : public Tetromino
{
public:
	ZTetromino()
	{
		id = 6;
		cells[0] = { Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 2), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(2, 1), Position(2, 2) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 0) };
		move(0, 3);
	}
};


class TTetromino : public Tetromino
{
public:
	TTetromino()
	{
		id = 7;
		cells[0] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(1, 2) };
		cells[1] = { Position(0, 1), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[2] = { Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 1) };
		cells[3] = { Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1) };
		move(0, 3);
	}
};