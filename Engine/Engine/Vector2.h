#ifndef __VECTOR2_H__
#define __VECTOR2_H__

template<class T = float>
struct Vector2
{
public:
	T x;
	T y;

public:
	Vector2(T X = T(), T Y = T()) : x(X), y(Y) {}
	Vector2(Vector2& model) : x(model.x), y(model.y) {}
	virtual ~Vector2() {}

	// test operator
	Vector2& operator==(Vector2& other) { return (this->x == other.x && this->y == other.y); }
	Vector2& operator!=(Vector2& other) { return !(this == other); }

	// arithmetic operator
	Vector2 operator+(Vector2& other) { return Vector2(this->x + other.x, this->y + other.y); }
	Vector2 operator-(Vector2& other) { return Vector2(this->x - other.x, this->y - other.y); }
	Vector2 operator*(T val) { return Vector2(this->x * val, this->y * val); }
	Vector2 operator/(T val) { return Vector2(this->x / val, this->y / val); }

	// assignment operator
	Vector2& operator=(Vector2& other) { this->x = other.x; this->y = other.y; return *this; }
	Vector2& operator+=(Vector2& other) { this = this + other; return *this; }
	Vector2& operator-=(Vector2& other) { this = this - other; return *this; }
	Vector2& operator*=(T val) { this = this * val; return *this; }
	Vector2& operator/=(T val) { this = this / val; return *this; }

	// methods
	inline T SquaredMagnitude() { return (pow(this->x, 2) + pow(this->y, 2)); }
	inline T Magnitude() { return (sqrt(this->SqrMagnitude())); }
	inline void Normalize() { this /= this->Magnitude(); }
	inline Vector2 Normalized() { return Vector2(this).Normalize(); }
	inline float Angle() { return atan2(this->y, this->x); }

	// static methods
	inline static T SquaredDistance(Vector2 a, Vector2 b) { b -= a; return b.SquaredMagnitude(); }
	inline static T Distance(Vector2 a, Vector2 b) { b -= a; return b.Magnitude(); }
	inline static float Angle(Vector2 a, Vector2 b) { return Vector2(b - a).Angle(); }

}; // Vector2

#endif // __VECTOR2_H__