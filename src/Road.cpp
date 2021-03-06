#include "Road.hpp"


Road::Road()
{

}

Road::Road(int width, int height, int depth)
{
	this->width = width;
	this->height = height;
	this->depth = depth;
}

Road::~Road() {

}

void Road::init()
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	float z = this->getPosition().z;

	float width = this->width;
	float depth = this->depth;
	float height = this->height;
}
