#pragma once
class Racket
{
private:
	int x, y, width;
public:
	Racket();
	void initObject(int x, int width);
	void moveObj(int iY);
	void putObject(char arr[25][56], char symbol);
	~Racket();
};

