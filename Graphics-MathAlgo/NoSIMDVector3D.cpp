#include "NoSIMDVector3D.h"

NoSIMDVector3D::NoSIMDVector3D(float x = 0.f, float y = 0.f, float z = 0.f)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

NoSIMDVector3D::NoSIMDVector3D(const NoSIMDVector3D& vector)
{
    this->x = vector.x;
    this->y = vector.y;
    this->z = vector.z;
}

bool NoSIMDVector3D::Equals(NoSIMDVector3D base, NoSIMDVector3D other)
{
    if (base.x == other.x && base.y == other.y && base.z == other.z)
    {
        return true;
    }
    return false;
}

NoSIMDVector3D& NoSIMDVector3D::operator+=(const NoSIMDVector3D& lhs)
{
    x += lhs.x;
    y += lhs.y;
    z += lhs.z;

    return *this;
}

std::string NoSIMDVector3D::ToString()
{
    std::string strRep = "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z);
    return strRep;
}

bool operator==(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs)
{
    if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
    {
        return true;
    }
    return false;
}
