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
bool gameOver, xlm, xrm, yum, ydm;
const int width = 50, height = 11;
int enemys[100];
int x, y, round, enmyCount;

void Setup() {

	x = 5;
	y = height/2;
	round = 1;
	gameOver = false;

}

void Draw() {

	system ("CLS");
	for(int i = 0; i <= height; i++) {

		for(int j = 0; j <= width; j++) {

			if (i == 0 || j == 0 || i == (height) || j == (width))
				cout << "# ";
			else if (i == y && j == x)
				cout << "E=";
			else
				cout << "  ";
		}
		cout << endl;
	}

}

void Logic() {

	xlm = true;
	xrm = true;
	ydm = true;
	yum = true;

	// Barriers blocking further movement...
	if (x <= 1) {
		xlm = false;
		x = 1;
	}
	if (x >= width-1) {
		xrm = false;
		x = width-1;
	}
	if (y <= 1) {
		yum = false;
		y = 1;
	}
	if (y >= height-1) {
		ydm = false;
		y = height-1;
	}

	// This determines the end of a round...


	// This determines the number of enemies based on the round...
	switch (round) {
		case 1:
			enmyCount = 10;
			break;
		case 2:
			enmyCount = 20;
			break;
		case 3:
			enmyCount = 30;
			break;
		case 4:
			enmyCount = 40;
			break;
		case 5:
			enmyCount = 50;
			break;
		case 6:
			enmyCount = 60;
			break;
		case 7:
			enmyCount = 70;
			break;
		case 8:
			enmyCount = 80;
			break;
		case 9:
			enmyCount = 90;
			break;
		case 10:
			enmyCount = 100;
			break;
	}
}

void Input() {

	// Assigning the correct output to input...
	while (_kbhit()) {
		switch (_getch()) {
			case 'a':
				if (xlm)
					x -= 2;
				break;
			case 'd':
				if (xrm)
					x += 2;
				break;
			case 's':
				if (ydm)
					y++;
				break;
			case 'w':
				if (yum)
					y--;
				break;
			case 'x':
				gameOver = true;
				break;
		}
	}


}

void Enemies() {

	for(int i = 0; i < enmyCount) {

	}

}

int main() {

	Setup();
	do {
		Input();
		Draw();
		Logic();

	} while(!gameOver);

	return 0;
}
