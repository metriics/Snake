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
#include <time.h>
#include <stdlib.h>
#include "Food.h"
#include "SnakeTrail.h"

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
vec2 positions[50];
vec2 prevPositions[50];
SnakeTrail trails[50];
Food foodList[1];
vec2 cppIsDumb;
int score = 0;
static Board game;

void askToQuit() {
	std::cout << "Enter r to resume, e to restart, and q to quit." << endl;
	cin >> choice;
	if (choice == "q") {
		exit(0);
	}
	else if (choice == "e") {
		// restart
		game = Board();
		score = 0;
		return;

	}
	else if (choice == "r") {
		return;
	}
}

void gameOver() {
	exit(0);
}

void input()
{

}

int main() {
	//int page = 0;
	srand((int)time(0));
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); 
	//Board gameBoard("test");


	while (playing)
	{
		// GET KEYBOARD INPUT
	
		if (_kbhit())
		{
			c = 0;

			switch (c = _getch())
			{
			case KEY_UP:
				keys[1] = true;
				game.snake.dir = 3;
				break;

			case KEY_DOWN:
				keys[2] = true;
				game.snake.dir = 1;
				break;

			case KEY_LEFT:
				keys[3] = true;
				game.snake.dir = 4;
				//std::cout << "left" << endl;
				break;

			case KEY_RIGHT:
				keys[4] = true;
				game.snake.dir = 2;
				//std::cout << "right" << endl;
				break;

			case KEY_ESC:
				keys[5] = true;

				askToQuit();
				break;

			//default: 
				//cout << "test" << endl;
			}

		}
		//Sleep(500);
		//

		game.ate = false;
		
		game.snake.prevPos = game.snake.pos;
		for (int i = 0; i < game.snake.len; i++) {
			trails[i].previousPos = trails[i].pos;
		}
		if (game.snake.dir == 1) {
			game.snake.pos.y += 1;
		}
		else if (game.snake.dir == 2) {
			game.snake.pos.x += 1;
		}
		else if (game.snake.dir == 3) {
			game.snake.pos.y -= 1;
		}
		else if (game.snake.dir == 4) {
			game.snake.pos.x -= 1;
		}
		

		// Randomly place Food on the board within borders, no more than 3 food pieces at once

		if (foodList[0].pos == cppIsDumb) {
			foodList[0] = Food();
		}
		game.placeOnBoard(foodList[0].food, foodList[0].pos);
		//cout << foodList[0].pos.x << " " << foodList[0].pos.y << endl;
		std::cout << "Score:  " << score << endl;

		// CHECK FOR SNAKE LENGTH
		if (game.snake.len > 50) {
			gameOver();
		}
		//

		game.placeOnBoard(game.snake.head, game.snake.pos);
		if (game.ate == true) {
			foodList[0] = Food();
			game.snake.len += game.score;
			score += game.score * 10;
		}

		for (int i = 0; i < game.snake.len; i++) {
			if (i == 0) {
				trails[0].pos = game.snake.prevPos;
			}
			else {
				trails[i].pos = trails[i - 1].previousPos;
			}
			game.placeOnBoard(trails[i].trail, trails[i].pos);
		}
		game.updateBoard();
	}
	return 0;
}