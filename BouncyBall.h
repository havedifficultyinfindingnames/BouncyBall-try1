#pragma once
#include "stdafx.h"

enum class BlockKind :int{ noBlock, squareBlock, circleBlock, bullet };

struct Position
{
	int x;
	int y;
};

struct Block
{
	BlockKind kind;
	int num;
	Block(BlockKind kind = BlockKind::noBlock, int num = 0);
};

class BouncyBall : public QWidget
{
private:
	const int width = 500;
	const int height = 800;
	const int ballRadium = 5;
private:
	int column;
	int round;
	int level;
	std::queue<std::vector<Block>>* map;
	std::stack<Position>* ball;
	int ballNum;
	int landingPos;

public:
	BouncyBall(int column = 8,QWidget* parent = nullptr);
	~BouncyBall();
	// logical functions
	void raiseLevel();
	void createBlocks();
	void deleteLine();
	void addBall();
	// drawing functions
	void moveDown();
	void shoot(int x, int y);

protected:
	virtual void mousePressEvent(QMouseEvent*) override;
	virtual void paintEvent(QPaintEvent*) override;
};
