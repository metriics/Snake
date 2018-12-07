/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#include "vec2.h"
#include "string.h"

vec2::vec2() {
	this->x = 0.0f;
	this->y = 0.0f;
}

vec2::vec2(const int x, const int y) {
	this->x = (float)x;
	this->y = (float)y;
}

vec2::vec2(const double x, const double y) {
	this->x = (float)x;
	this->y = (float)y;
}

vec2::vec2(const float x, const float y) {
	this->x = x;
	this->y = y;
}

vec2::vec2(vec2& vec) {
	this->x = vec.x;
	this->y = vec.y;
}

char * vec2::toBytes() {
	char * chr = new char[sizeof(vec2)];
	memcpy(chr, this, sizeof(this));
	return chr;
}

vec2 vec2::operator+(const vec2 a) const {
	vec2 sum;
	sum.x = x + a.x;
	sum.y = y + a.y;
	return sum;
}

vec2 vec2::operator-(const vec2 a) const {
	vec2 sum;
	sum.x = x - a.x;
	sum.y = y - a.y;
	return sum;
}

vec2 vec2::operator*(const vec2 a) const {
	vec2 sum;
	sum.x = x * a.x;
	sum.y = y * a.y;
	return sum;
}

vec2 vec2::operator/(const vec2 a) const {
	vec2 sum;
	sum.x = x / a.x;
	sum.y = y / a.y;
	return sum;
}

vec2 operator+(const float a, const vec2 b) {
	vec2 temp;
	temp.x = a + b.x;
	temp.y = a + b.y;
	return temp;
}

vec2 operator-(const float a, const vec2 b) {
	vec2 temp;
	temp.x = a - b.x;
	temp.y = a - b.y;
	return temp;
}