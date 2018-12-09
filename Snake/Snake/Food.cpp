/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "Food.h"
#include <iostream>
#include <stdlib.h>

Food::Food() {

	vec2 temp;
	for (int i = 0; i < 2; i++) {
		int x = rand() % 48 + 1;
		int y = rand() % 28 + 1;
		//std::cout << x << " " << y << std::endl;
		temp.x = x;
		temp.y = y;
	}
	this->pos = temp;
	this->points = 1;
}

Food::Food(vec2 pos, int points) {
	this->pos = pos;
	this->points = points;
}