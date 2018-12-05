#include "Snake.h"

Snake::Snake() {
	this->dir = 1;
	this->len = 1;
	this->pos = vec2(14, 14);
}

Snake::Snake(vec2 pos) {
	this->dir = 1;
	this->len = 1;
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