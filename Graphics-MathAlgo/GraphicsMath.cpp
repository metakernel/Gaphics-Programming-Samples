#include "GraphicsMath.h"

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

NoSIMDVector3D NoSIMDVector3D::Zero()
{
    return NoSIMDVector3D(0.f,0.f,0.f);
}

NoSIMDVector3D NoSIMDVector3D::Right()
{
    return NoSIMDVector3D(1.f,0.f,0.f);
}

NoSIMDVector3D NoSIMDVector3D::Up()
{
    return NoSIMDVector3D(0.f, 1.f, 0.f);
}

NoSIMDVector3D NoSIMDVector3D::Forward()
{
    return NoSIMDVector3D(0.f, 0.f, 1.f);
}

NoSIMDVector3D& NoSIMDVector3D::operator=(const NoSIMDVector3D& lhs)
{
    x = lhs.x;
    y = lhs.y;
    z = lhs.z;

    return *this;
}

NoSIMDVector3D& NoSIMDVector3D::operator+=(const NoSIMDVector3D& lhs)
{
    x += lhs.x;
    y += lhs.y;
    z += lhs.z;

    return *this;
}

NoSIMDVector3D& NoSIMDVector3D::operator-=(const NoSIMDVector3D& lhs)
{
    *this += (-lhs);

    return *this;
}

NoSIMDVector3D NoSIMDVector3D::operator-() const
{
    return NoSIMDVector3D(-x,-y,-z);
}


NoSIMDVector3D& NoSIMDVector3D::operator*=(const float lhs)
{
    x *= lhs;
    y *= lhs;
    z *= lhs;

    return *this;
}

NoSIMDVector3D& NoSIMDVector3D::operator/=(const float lhs)
{
    x /= lhs;
    y /= lhs;
    z /= lhs;

    return *this;
}

std::string NoSIMDVector3D::ToString()
{
    std::string strRep = "X: " + std::to_string(x) + ", Y: " + std::to_string(y) + ", Z: " + std::to_string(z);
    return strRep;
}

float NoSIMDVector3D::GetLength()
{
    // The formula is the squared root of all its component at power 2
    float result = sqrtf(powf(x,2) + powf(y,2) + powf(z,2));
    return result;
}

NoSIMDVector3D NoSIMDVector3D::Normalize()
{
    // Get normalize vector by dividing component with its length
    return *this / this->GetLength();
}

bool operator==(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs)
{
    if (lhs.x == rhs.x && lhs.y == rhs.y && lhs.z == rhs.z)
    {
        return true;
    }
    return false;
}

NoSIMDVector3D operator+(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs)
{
    return NoSIMDVector3D(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
}

NoSIMDVector3D operator-(const NoSIMDVector3D& lhs, const NoSIMDVector3D& rhs)
{
    return NoSIMDVector3D(lhs.x + -rhs.x, lhs.y + -rhs.y, lhs.z + -rhs.z);
}

NoSIMDVector3D operator*(const NoSIMDVector3D& lhs, const float rhs)
{
    return NoSIMDVector3D(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

NoSIMDVector3D operator/(const NoSIMDVector3D& lhs, const float rhs)
{
    return NoSIMDVector3D(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
}
