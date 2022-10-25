#pragma once
class Vector2
{
public:
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	//operators that will allow us to perform math functions on the vector

	Vector2 operator+(const Vector2& OtherVector);
	Vector2 operator+=(const Vector2& OtherVector);

	Vector2 operator-(const Vector2& OtherVector);
	Vector2 operator-=(const Vector2 & OtherVector);

	Vector2 operator*(const float& Scalar);
	Vector2 operator*=(const float& Scalar);

	Vector2 operator/(const float& Scalar);
	Vector2 operator/=(const float& Scalar);

	// checking if x = y
	bool operator==(const Vector2& OtherVector);
	bool operator!=(const Vector2& OtherVector);

	//what is the lenth of both the x and y;
	float Length();

	void Normalise();
	Vector2 Normalised();
	
	// this is a quick function to return a 0,0 vector
	Vector2 Zero();

	//cordinates stored in the veector
	float x;
	float y;
};

