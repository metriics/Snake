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

int main() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); 

	Board game;

	Board gameBoard("test");

	while (playing)
	{
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			cout << endl << "Up" << endl; //key up
			keys[1] = true;
			break;
		case KEY_DOWN:
			cout << endl << "Down" << endl; // key down
			keys[2] = true;
			break;
		case KEY_LEFT:
			cout << endl << "Left" << endl; // key left
			keys[3] = true;
			break;
		case KEY_RIGHT:
			cout << endl << "Right" << endl; // key right
			keys[4] = true;
			break;
		case KEY_ESC:
			cout << endl << "ESC" << endl; // key esc
			keys[5] = true;
			askToQuit();
			break;
		}
	}
	// Here we write Snake.

	return 0;
}