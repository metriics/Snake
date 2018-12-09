/*
Snake

Stephane Gagnon		100694227
Charley Fai			100698666
Ryan Burton			100707511
Jonah Griffin		100702748
Kennedy Adams		100632983
*/

#pragma once

class vec2 {
public:
	float x;
	float y;

	vec2();
	vec2(const int x, const int y);
	vec2(const double a, const double b);
	vec2(const float x, const float y);
	vec2(vec2& vec);

	char* toBytes();

	vec2 operator+(const vec2 a) const;
	vec2 operator-(const vec2 a) const;
	vec2 operator*(const vec2 a) const;
	vec2 operator/(const vec2 a) const;

	bool operator==(const vec2 a) const;


	friend vec2 operator+(const float a, const vec2 b);
	friend vec2 operator-(const float a, const vec2 b);
};