/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "Snake.h"

Snake::Snake() {
	this->dir = 3;
	this->len = 0;
	this->pos = vec2(24, 14);
}

Snake::Snake(vec2 pos) {
	this->dir = 3;
	this->len = 0;
	this->pos = pos;
}

void Snake::setPos(vec2 pos) {
	this->pos = pos;
}

void Snake::setDir(int dir) {
	this->dir = dir;
}

void Snake::addLen() {
	this->len += 1;
}