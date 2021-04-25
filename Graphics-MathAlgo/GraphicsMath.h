#pragma once

#include <string>

/// <summary>
/// This is a raw implementation of a 3d vector structure not using SIMD or any other lib
/// </summary>
struct NoSIMDVector3D
{
	/// <summary>
	/// Default constructor
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="z"></param>
	NoSIMDVector3D(float x, float y, float z);

	/// <summary>
	/// Copy constructor
	/// </summary>
	/// <param name="vector"></param>
	NoSIMDVector3D(const NoSIMDVector3D& vector);

	float x;
	float y;
	float z;

	/// <summary>
	/// Return a string representing the vector
	/// </summary>
	/// <returns>Return a string in the form: "(x, y, z)" </returns>
	std::string ToString();

	/// <summary>
	/// Get the current vector length
	/// </summary>
	/// <returns></returns>
	float GetLength();

	/// <summary>
	/// Get a unit vector from the current one
	/// </summary>
	/// <returns></returns>
	NoSIMDVector3D Normalize();

	//=============== Operators overload========================//
	friend bool operator==(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs);
	friend NoSIMDVector3D operator+(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs);
	friend NoSIMDVector3D operator-(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs);
	friend NoSIMDVector3D operator*(const NoSIMDVector3D& lhs, const float rhs);
	friend NoSIMDVector3D operator/(const NoSIMDVector3D& lhs, const float rhs);
	NoSIMDVector3D& operator=(const NoSIMDVector3D& lhs);
	NoSIMDVector3D& operator+=(const NoSIMDVector3D& lhs);
	NoSIMDVector3D& operator-=(const NoSIMDVector3D& lhs);
	NoSIMDVector3D operator-() const;
	NoSIMDVector3D& operator*=(const float lhs);
	NoSIMDVector3D& operator/=(const float lhs);

	//================Static functions=========================//

	/// <summary>
	/// Same as the operator == but in a static version
	/// </summary>
	/// <param name="base"></param>
	/// <param name="other"></param>
	/// <returns></returns>
	static bool Equals(NoSIMDVector3D base, NoSIMDVector3D other);

	/// <summary>
	/// Return the dot product of two vector
	/// </summary>
	/// <param name="base"></param>
	/// <param name="other"></param>
	/// <returns></returns>
	static float DotProduct(NoSIMDVector3D base, NoSIMDVector3D other);

	/// <summary>
	/// Compute and return a crossproduct generated vector
	/// </summary>
	/// <param name="base"> - The base vector</param>
	/// <param name="other">- The other vector</param>
	/// <returns>- Return the cross product as a NoSIMDVector3D</returns>
	static NoSIMDVector3D CrossProduct(NoSIMDVector3D base, NoSIMDVector3D other);

	/// <summary>
	/// This create and return a zero vector
	/// </summary>
	/// <returns>NoSIMDVector(0.f,0.f,0.f)</returns>
	static NoSIMDVector3D Zero();

	/// <summary>
	/// This create and return a right normalised vector
	/// </summary>
	/// <returns>NoSIMDVector3D(1.f,0.f,0.f)</returns>
	static NoSIMDVector3D Right();

	/// <summary>
	/// This create and return a right normalised vector
	/// </summary>
	/// <returns>NoSIMDVector3D(0.f,1.f,0.f)</returns>
	static NoSIMDVector3D Up();

	/// <summary>
	/// This create and return a right normalised vector
	/// </summary>
	/// <returns>NoSIMDVector3D(0.f,0.f,1.f)</returns>
	static NoSIMDVector3D Forward();
};

