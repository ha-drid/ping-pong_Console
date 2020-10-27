#pragma once
class Ball
{
private:
	float x, y;
	int height, width;
	int nX, nY;
	float alfa, speed;
public:
	Ball();
	void initObject(float x, float y, int height, int width);
	void moveObj(float x, float y);
	void Ball_Check_Colision(char arr[25][56]);
	bool Ball_Check_Pos(int min, int max);
	void putObject(char arr[25][56], char symbol);
	~Ball();
};

