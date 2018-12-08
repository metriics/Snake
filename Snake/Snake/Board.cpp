/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {
	int fps = 2;
	this->timing = 1000 / fps;
}

Board::Board(string test) {
	int fps = 2;
	this->timing = 1000 / fps;
	if (test == "test") {
		cout << "Press enter to test." << endl;
		cin.get();

		vec2 bpos(50, 50); // broken pos to test error msg
		vec2 opos(1, 15); // ok pos to test placement

		this->updateBoard(); // print
		cout << "Press enter to place OK test char and print" << endl;
		cin.get();
		this->placeOnBoard('t', opos); // place ok test char
		this->updateBoard(); // print
		cout << "Press enter to place BAD test char and print" << endl;
		cin.get();
		this->placeOnBoard('t', bpos); // place bad test char
		this->updateBoard(); // print
	}
}

void Board::placeOnBoard(char obj, vec2 pos) {
	vec2 temp(pos.y, pos.x);
	if (obj == '@' && (curBoard[(int)temp.y][(int)temp.x] == '|' || curBoard[(int)temp.y][(int)temp.x] == '-' || curBoard[(int)temp.y][(int)temp.x] == '*')) {
		deathScreen();
	}

	else if (obj == '#' && (curBoard[(int)temp.y][(int)temp.x] == '|' || curBoard[(int)temp.y][(int)temp.x] == '-' || curBoard[(int)temp.y][(int)temp.x] == '*')) {
		MessageBox(nullptr, TEXT(""), TEXT("food spawn out of bounds"), MB_OK);
	}
	this->curBoard[(int)temp.x][(int)temp.y] = obj; // replace char on board at pos with char obj
}

void Board::clearBoard() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			curBoard[i][j] = emptyBoard[i][j];
		}
	}
	system("cls");
}

void Board::printBoard() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			cout << this->curBoard[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Board::updateBoard() {
	Board::printBoard();
	Sleep(this->timing);
	Board::clearBoard();
}

void Board::deathScreen() {
	std::cout << "                                                                                " << std::endl;
	std::cout << "  |||||||||| |||||||||| |||    ||| ||||||||||                                   " << std::endl;
	std::cout << "  |||        |||    ||| ||||  |||| |||                                          " << std::endl;
	std::cout << "  |||  ||||| |||||||||| ||| || ||| ||||||                                       " << std::endl;
	std::cout << "  |||    ||| |||    ||| |||    ||| |||                                          " << std::endl;
	std::cout << "  |||||||||| |||    ||| |||    ||| ||||||||||                                   " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << "                  |||||||||| |||    ||| |||||||||| ||||||||||    |||    |||     " << std::endl;
	std::cout << "                  |||    |||  |||  |||  |||        |||    |||         |||       " << std::endl;
	std::cout << "                  |||    |||   ||  ||   ||||||     ||||||||||         ||        " << std::endl;
	std::cout << "                  |||    |||    ||||    |||        |||  |||           |||       " << std::endl;
	std::cout << "                  ||||||||||     ||     |||||||||| |||    |||    |||    |||     " << std::endl;
	std::cout << "                                                                                " << std::endl;
	std::cout << endl;
	std::cout << "Press enter to quit..." << endl;
	cin.get();
	exit(0);
}