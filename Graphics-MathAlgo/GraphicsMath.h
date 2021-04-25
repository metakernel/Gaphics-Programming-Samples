#pragma once
/// <summary>
/// This is a raw implementation of a 3d vector structure not using SIMD or any other lib
/// </summary>

#include <string>

struct NoSIMDVector3D
{
public:
	// Default constructor
	NoSIMDVector3D(float x, float y, float z);
	// Copy constructor
	NoSIMDVector3D(const NoSIMDVector3D& vector);

	float x;
	float y;
	float z;

	// Same as == but in a static function
	static bool Equals(NoSIMDVector3D base, NoSIMDVector3D other);

	// Transform vector into a showable string representation
	std::string ToString();

	//=============== Operators overload========================//
	friend bool operator==(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs);

	NoSIMDVector3D& operator+=(const NoSIMDVector3D& lhs);
};

