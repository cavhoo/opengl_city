#include "skyscraper.hpp"

Skyscraper::Skyscraper(Vec3f pos, float width, float height, float depth, int roofs): Building(pos)
{
	this->roofs = roofs;
	this->width = width;
	this->height = height;
	this->depth = depth;
	this->init();
}

void Skyscraper::init()
{
	srand(time(0));

	RandomGenerator* rnd = RandomGenerator::getInstance();

	for (int i = 1; i <= roofs; i++)
	{
		float nWidth = (rnd->getIntFromRange(80/i, 100/i) / 100.0) * width;
		float nHeight = (rnd->getIntFromRange(10*i, 30*i) / 100.0) * height;
		float nDepth = (rnd->getIntFromRange(80/i, 100/i) / 100.0) * depth;

		BoxBuilding *box = new BoxBuilding(getPosition(), nWidth, nHeight, nDepth);
		this->addChild(box);
	}
}
