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

	friend vec2 operator+(const float a, const vec2 b);
	friend vec2 operator-(const float a, const vec2 b);

	//vec2 operator+=(const vec2 a) const;
	//vec2 operator-=(const vec2 a) const;
	//vec2 operator*=(const vec2 a) const;
	//vec2 operator/=(const vec2 a) const;
};