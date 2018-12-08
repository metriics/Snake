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

class Food {
public:
	vec2 pos;
	int points;
	char food = '#';

	Food();
	Food(vec2 pos, int points);
};