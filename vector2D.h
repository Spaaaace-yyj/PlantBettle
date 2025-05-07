#ifndef _VECTOR2D_H_
#define _VECTOR2D_H_

#include <math.h>

class Vector2D {
public:
	Vector2D() {
		x = 0; 
		y = 0;
	}
	Vector2D(float x, float y) : x(x), y(y){
	}
	~Vector2D() = default;

	float length() {
		return sqrt(x * x + y * y);
	}

	Vector2D normalize() {
		float len = length();
		if (len == 0) {
			return Vector2D(0, 0);
		}
		return Vector2D(x / len, y / len);
	}

	Vector2D operator+(const Vector2D& vector) {
		return Vector2D(x + vector.x, y + vector.y);
	}

	void operator+=(const Vector2D& vector) {
		x += vector.x;
		y += vector.y;
	}

	Vector2D operator-(const Vector2D& vector) {
		return Vector2D(x - vector.x, y - vector.y);
	}

	void operator-=(const Vector2D& vector) {
		x -= vector.x;
		y -= vector.y;
	}

	//µã³Ë
	float operator*(const Vector2D& vec) {
		return x * vec.x + y * vec.y;
	}

	Vector2D operator*(float val) const {
		return Vector2D(x * val, y * val);
	}
	
	void operator*=(float vel) {
		x *= vel;
		y *= vel;
	}
public:
	float x, y;
};

#endif