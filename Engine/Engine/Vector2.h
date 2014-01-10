#ifndef __VECTOR2_H__
#define __VECTOR2_H__

template<class T = float>
class Vector2
{
public:
	T x;
	T y;

public:
	Vector2(T X, T Y) : x(X), y(Y) {}
	virtual ~Vector2() {}

	Vector2& operator=(Vector2& other) { this->x = other.x; this->y = other.y; return *this; }
	Vector2& operator+(Vector2& other) { this->x += other.x; this->y += other.y; return *this; }
	Vector2& operator-(Vector2& other) { this->x -= other.x; this->y -= other.y; return *this; }
	Vector2& operator+=(Vector2& other) { this = this + other; return *this; }
	Vector2& operator-=(Vector2& other) { this = this - other; return *this; }

	inline T SqrMagnitude() { return (pow(this->x, 2) + pow(this->y, 2)); }
	inline T Magnitude() { return (sqrt(this->SqrMagnitude())); }
	inline static T Distance(Vector2 a, Vector2 b) { b -= a; return b.Magnitude() }
}; // Vector2

#endif // __VECTOR2_H__