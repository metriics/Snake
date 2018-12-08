/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511 
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "Board.h"
#include <conio.h>
#include <Windows.h>
#include <iostream>

#include "Food.h"
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
using namespace std;

bool playing = true;
string choice;
bool keys[5] = { false, false, false, false, false };
			//	UP		DOWN	LEFT	RIGHT	ESC
int c;

void askToQuit() {
	cout << "Enter r to resume, or q to quit." << endl;
	cin >> choice;
	if (choice == "q") {
		exit(0);
	}
	else if (choice == "r") {
		return;
	}
}

void gameOver() {
	exit(0);
}

int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); 

	Board game;
	//Board gameBoard("test");
	Food foodList[3];

	while (playing)
	{
		// GET KEYBOARD INPUT
		c = 0;
		c = _getch();
		if (c == KEY_UP) {
			keys[1] = true;
			break;
		}
		else if (c == KEY_DOWN) {
			keys[2] = true;
			break;
		}
		else if (c == KEY_LEFT) {
			keys[3] = true;
			break;
		}
		else if (c == KEY_RIGHT) {
			keys[4] = true;
			break;
		}
		else if (c == KEY_ESC) {
			keys[5] = true;
			askToQuit();
			break;
		}
		else {
			
		}

		//
		cout << "test" << endl;
		// Randomly place Food on the board within borders, no more than 3 food pieces at once
		for (int i = 0; i > 3; i++) {
			if (game.curBoard[(int)foodList[i].pos.y][(int)foodList[i].pos.x] != '#') {
				foodList[i] = Food();
			}
			game.placeOnBoard(foodList[i].food, foodList[i].pos);
			cout << foodList[i].pos.x << " " << foodList[i].pos.y << endl;
		}



		// CHECK FOR SNAKE LENGTH
		if (game.snake.len > 50) {
			gameOver();
		}
		//


	}
	return 0;
}