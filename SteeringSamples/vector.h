#pragma once

struct vector2
{
	float x;
	float y;

	vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vector2(float init_x, float init_y)
	{
		x = init_x;
		y = init_y;
	}

	void operator=(const vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
	}

	vector2 operator+(const vector2 &rhs)
	{
		vector2 result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		return result;
	}

	void operator+=(const vector2 &rhs)
	{
		(*this) = (*this) + rhs;
	}

	vector2 operator-(const vector2 &rhs)
	{
		vector2 result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		return result;
	}

	void operator-=(const vector2 &rhs)
	{
		(*this) = (*this) - rhs;
	}

	vector2 operator*(const vector2 &rhs)
	{
		vector2 result;
		result.x = x * rhs.x;
		result.y = y * rhs.y;
		return result;
	}

	void operator*=(const vector2 &rhs)
	{
		(*this) = (*this) * rhs;
	}

	vector2 operator*(const float &rhs)
	{
		vector2 result;
		result.x = x * rhs;
		result.y = y * rhs;
		return result;
	}

	void operator*=(const float &rhs)
	{
		(*this) = (*this) * rhs;
	}
};

// utility functions for vector2
float magnitude(vector2 vector)
{
	return sqrt(vector.x * vector.x + vector.y* vector.y);
}

vector2 normalise(vector2 toNormalise)
{
	vector2 normalised;

	normalised.x = toNormalise.x / magnitude(toNormalise);
	normalised.y = toNormalise.y / magnitude(toNormalise);

	return normalised;
}
