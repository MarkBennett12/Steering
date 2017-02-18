#pragma once

/*
/// <summary>
/// 2 dimensional vector type plus utility functions
/// operators for all common operations
/// </summary>
*/
struct vector2
{
	float x;
	float y;

	/***********************************************************************************
	/// <summary>
	/// Default constructor
	/// </summary>
	***********************************************************************************/
	vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	/***********************************************************************************
	/// <summary>
	/// Constructor
	/// </summary>
	/// <param name="init_x">float init_x : initial x value</param>
	/// <param name="init_y">float init_y : initial y value</param>
	***********************************************************************************/
	vector2(float init_x, float init_y)
	{
		x = init_x;
		y = init_y;
	}

	/***********************************************************************************
	/// <summary>
	/// Assignment operator
	/// </summary>
	/// <param name="rhs">vector2 rhs : vector to assign</param>
	/// <returns>vector after assignment</returns>
	***********************************************************************************/
	vector2 operator=(const vector2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return (*this);
	}

	/***********************************************************************************
	/// <summary>
	/// Addition operator
	/// </summary>
	/// <param name="rhs">vector2 rhs : vector to add</param>
	/// <returns>vector after addition</returns>
	***********************************************************************************/
	vector2 operator+(const vector2 &rhs)
	{
		vector2 result;
		result.x = x + rhs.x;
		result.y = y + rhs.y;
		return result;
	}

	/***********************************************************************************
	/// <summary>
	/// Unary addition operator
	/// </summary>
	/// <param name="rhs">vector2 rhs : vector to add</param>
	/// <returns>vector after addition</returns>
	***********************************************************************************/
	vector2 operator+=(const vector2 &rhs)
	{
		(*this) = (*this) + rhs;
		return (*this);
	}

	/***********************************************************************************
	/// <summary>
	/// Subtraction operator
	/// </summary>
	/// <param name="rhs">vector2 rhs : vector to subtract</param>
	/// <returns>vector after subtraction</returns>
	***********************************************************************************/
	vector2 operator-(const vector2 &rhs)
	{
		vector2 result;
		result.x = x - rhs.x;
		result.y = y - rhs.y;
		return result;
	}

	/***********************************************************************************
	/// <summary>
	/// Unary subtraction operator
	/// </summary>
	/// <param name="rhs">vector2 rhs : vector to subtract</param>
	/// <returns>vector after subtraction</returns>
	***********************************************************************************/
	vector2 operator-=(const vector2 &rhs)
	{
		(*this) = (*this) - rhs;
		return (*this);
	}

	/***********************************************************************************
	/// <summary>
	/// Multiplication by scalar operator
	/// </summary>
	/// <param name="rhs">float rhs : scalar to multiply by</param>
	/// <returns>vector after multiplication</returns>
	***********************************************************************************/
	vector2 operator*(const float &rhs)
	{
		vector2 result;
		result.x = x * rhs;
		result.y = y * rhs;
		return result;
	}

	/***********************************************************************************
	/// <summary>
	/// Unary multiplication by scalar operator
	/// </summary>
	/// <param name="rhs">float rhs : scalar to multiply by</param>
	/// <returns>vector after multiplication</returns>
	***********************************************************************************/
	vector2 operator*=(const float &rhs)
	{
		(*this) = (*this) * rhs;
		return (*this);
	}
};

// utility functions for vector2
/***********************************************************************************
/// <summary>
/// Calculates the magnitude of the vector using Pythageras theorem and returns the
/// result as a float
/// </summary>
///
/// <param name="vector">vector2 vector : vector to calculate magnitude of</param>
/// <returns>vector magnitude as float</returns>
***********************************************************************************/
inline float magnitude(vector2 vector)
{
	return sqrt(vector.x * vector.x + vector.y* vector.y);
}

/***********************************************************************************
/// <summary>
/// Returns a normalised copy of the vector given as a paremter
/// </summary>
///
/// <param name="toNormalise">vector2 toNormalise : vector to calculate normalised version of</param>
/// <returns>normalised version of vector parameter</returns>
***********************************************************************************/
inline vector2 normalise(vector2 toNormalise)
{
	vector2 normalised;

	normalised.x = toNormalise.x / magnitude(toNormalise);
	normalised.y = toNormalise.y / magnitude(toNormalise);

	return normalised;
}

/***********************************************************************************
/// <summary>
/// Calculates dot product of input vectors and returns result as a float
/// </summary>
///
/// <param name="vector_a">vector2 vector_a : operand one</param>
/// <param name="vector_b">vector2 vector_b : operand two</param>
/// <returns>dot product of vector parameters as float</returns>
***********************************************************************************/
inline float dotProduct(vector2 vector_a, vector2 vector_b)
{
	return (vector_a.x * vector_b.x) + (vector_a.y * vector_b.y);
}

/***********************************************************************************
/// <summary>
/// Calculates the magnitude of the 2D cross product of input vectors and returns
/// result as a float, used for calculating angle direction
/// </summary>
///
/// <param name="vector_a">vector2 vector_a : operand one</param>
/// <param name="vector_b">vector2 vector_b : operand two</param>
/// <returns>magnitude of the 2D cross product of vector parameters as float</returns>
***********************************************************************************/
inline float crossProduct(vector2 vector_a, vector2 vector_b)
{
	return (vector_a.x * vector_b.y) - (vector_a.y * vector_b.x);
}