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

}; // Vector2

#endif // __VECTOR2_H__