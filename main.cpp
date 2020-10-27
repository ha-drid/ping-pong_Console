/*
* Здраствуйте меня зовут Намыс. Это мой первый проект сделаный самостоятельно,
* конешно я смотрел некоторые туториалы которые мне облегчили разработку
* например движения шарика как в арканоиде, дада как там.
* 
* видео где брал движения шарика, спасиба автору Антону за виео
* https://www.youtube.com/watch?v=g1MSTO1wCko 1-часть
* https://www.youtube.com/watch?v=868_DV1ksqE 2-часть
*/


#include <iostream>
#include <Windows.h>
#include "Racket.h"
#include "Ball.h"

#define widthMAP 55
#define heightMAP 25

char map[heightMAP][widthMAP + 1];
Racket player1, player2;
Ball ball;

bool run = false;

void initMap()
{
	for (int i = 0; i < widthMAP; i++)
		map[0][i] = '#';

	map[0][widthMAP] = '\0';

	
	for (int i = 0; i < widthMAP; i++)
		map[1][i] = ' ';
	map[1][widthMAP / 2] = '|';

	for (int i = 2; i < heightMAP - 1; i++)
		strncpy_s(map[i], map[1], widthMAP + 1);

	strncpy_s(map[heightMAP-1], map[0], widthMAP + 1);
}

void showMap()
{
	for (int i = 5; i < 11; i++)
		map[i][10] = '#';

	for (int i = 0; i < heightMAP; i++) 
	{
		std::cout << "\t    " << map[i] << std::endl;
	}
		
}

void initObj()
{
	player1.initObject(0, 7);
	player2.initObject(54, 7);
	ball.initObject(widthMAP / 2, heightMAP / 2, 1, 1);
}

void putObj()
{
	player1.putObject(map, '@');
	player2.putObject(map, '@');
	ball.putObject(map, '0');
}

void moveObj()
{
	player1.moveObj(0);
	if (GetKeyState('W') < 0) player1.moveObj(-1);
	if (GetKeyState('S') < 0) player1.moveObj(1);

	if (GetKeyState('D') < 0) run = true;

	player2.moveObj(0);
	if (GetKeyState('O') < 0) player1.moveObj(-1);
	if (GetKeyState('L') < 0) player2.moveObj(1);

}

void setCur(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}



int main()
{
	restart:
	initObj();
	do
	{
		if (run)
			ball.Ball_Check_Colision(map);

		if (ball.Ball_Check_Pos(0, widthMAP)) {
			run = false;
			system("cls");
			goto restart;/*для чего я исползовал оператор goto, я когда программировал мне тогда уже по быстее закончить и решил исползовать goto*/
		}


		initMap();
		moveObj();
		putObj();
		setCur(0, 0);
		showMap();
		
		Sleep(100);
	} while (GetKeyState(VK_ESCAPE) >= 0);
	return 0;
}
