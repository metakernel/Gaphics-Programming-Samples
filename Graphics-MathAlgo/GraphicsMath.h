#pragma once
/// <summary>
/// This is a raw implementation of a 3d vector structure not using SIMD or any other lib
/// </summary>

#include <string>

struct NoSIMDVector3D
{
	// Default constructor
	NoSIMDVector3D(float x, float y, float z);
	// Copy constructor
	NoSIMDVector3D(const NoSIMDVector3D& vector);

	float x;
	float y;
	float z;

	// Transform vector into a showable string representation
	std::string ToString();

	// Get the vector length
	float GetLength();

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

	// Same as == but in a static function comparing two vectors
	static bool Equals(NoSIMDVector3D base, NoSIMDVector3D other);

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

