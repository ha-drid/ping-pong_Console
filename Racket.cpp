#include <iostream>
#include "Racket.h"

Racket::Racket(){}

void Racket::initObject(int x, int width)
{
	this->x = x;
	this->y = (25 - width) / 2;
	this->width = width;
}

void Racket::moveObj(int iY)
{
	if (y < 1)
		y = 1;
	if (y + width >= 25)
		y = 25 - 1 - width;

	y += iY;
}

void Racket::putObject(char arr[25][56],char symbol)
{
	for (int i = y; i < (y + width); i++)
		arr[i][x] = symbol;
}

Racket::~Racket(){}