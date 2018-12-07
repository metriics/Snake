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
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_W 87
#define KEY_A 65
#define KEY_S 83
#define KEY_D 68
using namespace std;


int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 650, TRUE); // set console exactly 38 lines in height

	Board game;

	// Board gameBoard("test");
	int c = 0;
	while (true)
	{
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			cout << endl << "Up" << endl; //key up
			system("CLS");
			break;
		case KEY_DOWN:
			cout << endl << "Down" << endl; // key down
			system("CLS");
			break;
		case KEY_LEFT:
			cout << endl << "Left" << endl; // key left
			system("CLS");
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << endl; // key right
			system("CLS");
			break;
		case KEY_W:
			cout << endl << "W" << endl; // key w
			system("CLS");
			break;
		case KEY_A:
			cout << endl << "A" << endl; // key a
			system("CLS");
			break;
		case KEY_S:
			cout << endl << "S" << endl; // key s
			system("CLS");
			break;
		case KEY_D:
			cout << endl << "D" << endl; // key d
			system("CLS");
			break;
		case KEY_ESC:
			cout << endl << "ESC" << endl; // key esc
			system("CLS");
			exit(0);
			break;
		}
	}
	// Here we write Snake.

	return 0;
}