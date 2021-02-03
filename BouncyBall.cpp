#include "BouncyBall.h"

Block::Block(BlockKind kind, int num)
	: kind(kind)
	, num(num)
{
}

BouncyBall::BouncyBall(int column, QWidget* parent)
	: QWidget(parent)
	, column(column)
	, round(0)
	, level(1)
	, map(new std::queue<std::vector<Block>>)
	, ball(new std::stack<Position>)
	, ballNum(1)
	, landingPos(width / 2)
{
	std::vector<Block> temp;
	for (int i = 0; i < column; ++i)
	{
		temp.push_back(Block(BlockKind::squareBlock, 1));
	}
	map->push(temp);

	setFocus();
	setFixedSize(width, height);
	setAutoFillBackground(true);
	setStyleSheet("border:0.5px solid black");
}

BouncyBall::~BouncyBall()
{
	if (ball) delete[] ball;
	if (map) delete[] map;
}

void BouncyBall::raiseLevel()
{
	if (!(round % (round / 50))) ++level;
}

void BouncyBall::createBlocks()
{
	std::vector<Block> temp;
	for (int i = 0; i < column; ++i)
	{
		if ((rand() % (100 + level)) > 100)
			temp.push_back(Block(BlockKind::squareBlock, level));
		else
			temp.push_back(Block());
	}
	map->push(temp);
}

void BouncyBall::deleteLine()
{
	for (std::vector<Block>::iterator ite = map->front().begin(); ite == map->front().end(); ++ite)
		if (ite->num) return;
	map->pop();
	deleteLine();
}

void BouncyBall::addBall()
{
}
// movedown unfinished
void BouncyBall::moveDown()
{
	QTimer moveTimer;
	moveTimer.start(50);
	connect(&moveTimer, &QTimer::timeout, this, [this]() {

		});
}

void BouncyBall::shoot(int x, int y)
{
}

void BouncyBall::mousePressEvent(QMouseEvent*)
{
}

void BouncyBall::paintEvent(QPaintEvent*)
{
}

