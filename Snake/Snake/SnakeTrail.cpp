/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "SnakeTrail.h"

SnakeTrail::SnakeTrail() {
	this->pos = vec2();
}

SnakeTrail::SnakeTrail(vec2 pos) {
	this->pos = pos;
}