#pragma once
#include "vec2.h"

class Snake {
public:
	int dir; // 1 = up, 2 = right, 3 = down, 4 = left.
	int len;
	vec2 pos;
	char head = '@';
	char body = '*';

	Snake();
	Snake(vec2 pos);

	void setPos(vec2 pos);
	void setDir(int dir);
	void addLen();
};