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

		vec2 bpos(0, 0); // broken pos to test error msg
		vec2 opos(1, 15); // ok pos to test placement

		this->updateBoard(); // print
		cout << "Press enter to place OK test char and print" << endl;
		cin.get();
		this->placeOnBoard('t', opos); // place ok test char
		this->updateBoard(); // print
		cout << "Press enter to place BAD test char and print" << endl;
		cin.get();
		this->placeOnBoard('#', bpos); // place bad test char
		this->updateBoard(); // print
	}
}

void Board::placeOnBoard(char obj, vec2 pos) {
	score = 0;
	vec2 temp(pos.y, pos.x);
	if (obj == '@' && (curBoard[(int)temp.x][(int)temp.y] == '|' || curBoard[(int)temp.x][(int)temp.y] == '-' || curBoard[(int)temp.x][(int)temp.y] == '*')) {
		deathScreen();
	}

	else if (obj == '@' && curBoard[(int)temp.x][(int)temp.y] == '#') {
		score += 1;
		ate = true;
	}

	else if (obj == '#' && (curBoard[(int)temp.x][(int)temp.y] == '|' || curBoard[(int)temp.y][(int)temp.x] == '-' || curBoard[(int)temp.y][(int)temp.x] == '*')) {
		//MessageBox(nullptr, TEXT(""), TEXT("food spawn out of bounds"), MB_OK);
	}

	else {
		this->curBoard[(int)temp.x][(int)temp.y] = obj; // replace char on board at pos with char obj
	}
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
	//this->curBoard[20 + x][20] = "h";
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			cout << this->curBoard[i][j];
			
		}
		cout << "\n";
	}
	cout << "\n";
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

void Board::startScreen() {
	std::cout << "||-------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||-------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||                                                                                           ||" << std::endl;
	std::cout << "||                                                                                           ||" << std::endl;
	std::cout << "||                                       Group Members                                       ||" << std::endl;
	std::cout << "||                                                                                           ||" << std::endl;
	std::cout << "||                                  Ryan Burton - 100707511                                  ||" << std::endl;
	std::cout << "||                                  Charley Fai - 100698666                                  ||" << std::endl;
	std::cout << "||                                 Jonah Griffin - 100702748                                 ||" << std::endl;
	std::cout << "||                                 Kennedy Adams - 100632983                                 ||" << std::endl;
	std::cout << "||                                Stephane Gagnon - 100694227                                ||" << std::endl;
	std::cout << "||                                                                                           ||" << std::endl;
	std::cout << "||                                                                                           ||" << std::endl;
	std::cout << "||-------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||-------------------------------------------------------------------------------------------||" << std::endl;

	std::cin.ignore(); //lets user press enter to start the game
	system("CLS"); //Clears main menu console 

	std::cout << "||------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                 ||||||||||  |||    |||  |||         ||||||||||  ||||||||||               ||" << std::endl;
	std::cout << "||                 |||    |||  |||    |||  |||         |||         |||                      ||" << std::endl;
	std::cout << "||                 |||    |||  |||    |||  |||         |||         |||                      ||" << std::endl;
	std::cout << "||                 ||||||||||  |||    |||  |||         ||||||      ||||||||||               ||" << std::endl;
	std::cout << "||                 |||  |||    |||    |||  |||         |||                |||               ||" << std::endl;
	std::cout << "||                 |||   |||   |||    |||  |||         |||                |||               ||" << std::endl;
	std::cout << "||                 |||    |||  ||||||||||  ||||||||||  ||||||||||  ||||||||||               ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "|| The objective of this game is making the snake as long as you can. You do this by        ||" << std::endl;
	std::cout << "|| controlling the snake using the arrow keys, (up, down, left, right) on your keyboard     ||" << std::endl;
	std::cout << "|| and collect as fruits that appear on the screen. Doing so will increase the snakes tail. ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "|| But, if the player's snake collides with itself, or with the wall, the game will be over.||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "|| To acces the menu and pause the game, press 'ESC'. This will open the menu and show you  ||" << std::endl;
	std::cout << "|| three options: 'Press 'r' to resume', 'Press 'e' to restart', and 'Press 'q' to quit the ||" << std::endl;
	std::cout << "|| game'.                                                                                   ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||                                                                                          ||" << std::endl;
	std::cout << "||------------------------------------------------------------------------------------------||" << std::endl;
	std::cout << "||------------------------------------------------------------------------------------------||" << std::endl;

	std::cin.ignore(); //lets user press enter to start the game
	system("CLS"); //Clears main menu console  

	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "|||||||||| ||||    |||| |||||||||||| ||||    ||| |||||||||||      |||||||||||||||||||      " << std::endl;
	std::cout << "|||||||||| ||||    |||| ||||    |||| ||||   |||  |||||||||||     |||@|||||||||||||||||     " << std::endl;
	std::cout << "||||       |||||   |||| ||||    |||| ||||  |||   ||||          __|||||          |||||||    " << std::endl;
	std::cout << "||||       |||| |  |||| ||||    |||| |||| |||    ||||                          |||||||   ||" << std::endl;
	std::cout << "|||||||||| ||||  | |||| |||||||||||| |||||||     |||||||          ||||||||||||||||||||  |||" << std::endl;
	std::cout << "      |||| ||||  | |||| ||||    |||| |||| |||    ||||            ||||||||||||||||||||  ||||" << std::endl;
	std::cout << "      |||| ||||   ||||| ||||    |||| ||||  |||   ||||           |||||||               |||||" << std::endl;
	std::cout << "|||||||||| ||||    |||| ||||    |||| ||||   |||  |||||||||||     ||||||||||||||||||||||||||" << std::endl;
	std::cout << "|||||||||| ||||    |||| ||||    |||| ||||    ||| |||||||||||      |||||||||||||||||||||||| " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "                                                                                           " << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-------------------------------------------------------------------------------------------" << std::endl;

	std::cin.ignore(); //lets user press enter to start the game
	system("CLS"); //Clears main menu console 
}
