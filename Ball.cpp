#include "Ball.h"
#include <iostream>
#include <math.h>
#define M_PI 3.14

Ball::Ball(){}

void Ball::initObject(float x, float y, int height, int width)
{
	this->x = x;
	this->y = y;
	this->height = height;
	this->width = width;
	alfa = -4;
	speed = 1.0f;
	nX = (int)round(this->x);
	nY = (int)round(this->y);
}

void Ball::moveObj(float x, float y)
{
	this->x = x;
	this->y = y;
	nX = (int)round(this->x);
	nY = (int)round(this->y);
}


void Ball::Ball_Check_Colision(char arr[25][56])//Это метод только для шарика
{
	if (alfa < 0)alfa += M_PI * 2;
	if (alfa > M_PI * 2) alfa -= M_PI * 2;

	Ball bl;

	bl.nX = nX;
	bl.nY = nY;
	bl.alfa = alfa;

	moveObj(x + cos(alfa) * speed,
		y + sin(alfa) * speed);

	if ((arr[nY][nX] == '#') || (arr[nY][nX] == '@'))
	{

		if ((nX != bl.nX) && (nY != bl.nY))
		{
			if (arr[bl.nY][nX] == arr[nY][bl.nX])
				bl.alfa += M_PI;
			else
			{
				if (arr[bl.nY][nX] == '#')
					bl.alfa = (2 * M_PI - bl.alfa) + M_PI;
				else 
					bl.alfa = (2 * M_PI - bl.alfa);
			}
		}
		else if (nY == bl.nY) 
			bl.alfa = (2 * M_PI - bl.alfa) + M_PI;

		else 
			bl.alfa = (2 * M_PI - bl.alfa);


		nX = bl.nX;
		nY = bl.nY;
		alfa = bl.alfa;
		Ball_Check_Colision(arr);
	}
}

bool Ball::Ball_Check_Pos(int min,int max)
{
	return (nX > max) || (nX < min);
}

void Ball::putObject(char arr[25][56], char symbol)
{
	for (int i = nY; i < (nY + height); i++)
		for (int n = nX; n < (nX + width); n++)
			arr[i][n] = symbol;

}


Ball::~Ball() {}