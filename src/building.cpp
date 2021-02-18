#include "building.hpp"
#include "container.hpp"

Building::Building(): Container()
{
	this->setPosition({0.0, 0.0, 0.0});
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

void Building::render()
{
	Container::render();
}
