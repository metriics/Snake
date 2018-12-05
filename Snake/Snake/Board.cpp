#include "Board.h"
#include <iostream>
using namespace std;

Board::Board() {

}

Board::Board(string test) {
	if (test == "test") {
		cout << "Press enter to test." << endl;
		cin.get();

		vec2 bpos(50, 50); // broken pos to test error msg
		vec2 opos(15, 15); // ok pos to test placement

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
	if ((int)pos.x == 0 || (int)pos.x > 28) {
		MessageBox(nullptr, TEXT("OUT OF BOUNDS PLACEMENT"), TEXT("A character was placed out of bounds."), MB_OK);
	}
	// add code here to check if snake head is replacing food OR 
	// if its replacing a - or a | (pass snake through to the other side instad

	this->curBoard[(int)pos.x][(int)pos.y] = obj; // replace char on board at pos with char obj
}

void Board::clearBoard() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			curBoard[i][j] = emptyBoard[i][j];
		}
	}
	system("cls");
}

void Board::printBoard() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			cout << this->curBoard[i][j];
		}
		cout << endl;
	}
	cout << endl;
}

void Board::updateBoard() {
	Board::printBoard();
	Sleep(5000);
	Board::clearBoard();
}

void Board::resetBoard(char newBoard[30][30])
{
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			curBoard[i][j] = newBoard[i][j];
		}
	}
}
