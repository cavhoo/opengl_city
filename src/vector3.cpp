#include "vector3.hpp"
#include <string>

Vector3::Vector3()
{

}

Vector3::Vector3(int x, int y, int z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3* Vector3::add(Vector3 vec)
{
	this->x += vec.x;
	this->y += vec.y;
	this->z += vec.z;

	return this;
}

Vector3* Vector3::sub(Vector3 vec)
{
	this->x -= vec.x;
	this->y -= vec.y;
	this->z -= vec.z;

	return this;
}

Vector3* Vector3::multiply(Vector3 vec)
{
	this->x *= vec.x;
	this->y *= vec.y;
	this->z *= vec.z;

	return this;
}

Vector3* Vector3::distance(Vector3 vec)
{
	return new Vector3(
		this->x - vec.x,
		this->y - vec.y,
		this->z - vec.z
	);
}

std::string Vector3::toString()
{
	return "";
}
