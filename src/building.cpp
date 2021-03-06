#include "building.hpp"
#include "container.hpp"
#include <GL/gl.h>

Building::Building(): Container()
{
	this->setPosition({0.0, 0.0, 0.0});
	this->color = { 1.0, 1.0, 1.0 };
}

Building::Building(Vec3 position): Container()
{
	this->setPosition({ (float)position.x, (float) position.y, (float)position.z});
}

Building::Building(Vec3f position): Container()
{
	this->setPosition(position);
}

Building::~Building()
{
	this->verts.clear();
	this->verts.shrink_to_fit();
}

void Building::render(Vec3f parentPosition)
{
	glColor3f(this->color.r,this->color.g, this->color.b);
	Container::render(parentPosition);
}

void Building::setColor(Color3f color)
{
	this->color = color;
}
