#include "vector3f.hpp"
#include <cstdio>
#include <string>



Vector3f::Vector3f() {};

Vector3f::Vector3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3f* Vector3f::add(Vector3f vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;
	return this;
}

Vector3f* Vector3f::sub(Vector3f vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;
	return this;
}

Vector3f* Vector3f::multiply(Vector3f vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;
	return this;
}

Vector3f* Vector3f::distance(Vector3f vec)
{
	return new Vector3f(
		this->x - vec.x,
		this->y - vec.y,
		this->z - vec.z
	);
}

std::string Vector3f::toString()
{
	return "x: " + std::to_string(this->x) + " y: " + std::to_string(this->y) + " z: " + std::to_string(this->z);
}
