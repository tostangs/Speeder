//============================================================================
// Name        : Speeder Game
// Author      : Not me haha
// Version     : idk honestly
// Copyright   : Your copyright notice
// Description : Three dots for depression, the game for the excitement... ;)
//============================================================================

#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include "conio.h"

using namespace std;
bool gameOver;
const int width = 50, height = 11;
int x, y;
enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT};
eDirection dir;

void Setup() {

	x = 5;
	y = height/2;
	dir = STOP;
	gameOver = false;

}

void Draw() {

	system ("CLS");
	for(int i = 0; i < height; i++) {

		for(int j = 0; j < width; j++) {

			if (i == 0 || j == 0 || i == (height-1) || j == (width-1))
				cout << "# ";
			else if (i == y && j == x)
				cout << "E=";
			else
				cout << "  ";
		}
		cout << endl;
	}
	cout << "x position: " << x << " y position: " << y << endl;
}

void Logic() {

	switch(dir) {

		case STOP:
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		case RIGHT:
			x++;
			break;
		case LEFT:
			x--;
			break;
	}

	if (x == 0 || y == 0 || x == width-1 || y == height-1)
		gameOver = true;
}

void Input() {

	if (_kbhit()) {
			switch (_getch()) {
				case 'a':
					dir = LEFT;
					break;
				case 'w':
					dir = UP;
					break;
				case 's':
					dir = DOWN;
					break;
				case 'd':
					dir = RIGHT;
					break;
				case 'x':
					gameOver = true;
					break;
			}
		}

}

int main() {

	Setup();
	do {
		Draw();
		Sleep(25);
		Input();
		Logic();

	} while(!gameOver);

	return 0;
}
