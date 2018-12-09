/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#pragma once
#include "vec2.h"

class Snake {
public:
	int dir; // 1 = up, 2 = right, 3 = down, 4 = left.
	int len;
	vec2 pos;
	vec2 prevPos;
	char head = '@';

	Snake();
	Snake(vec2 pos);

	void setPos(vec2 pos);
	void setDir(int dir);
	void addLen();
};