#include "skyscraper.hpp"
#include <cstdio>

Skyscraper::Skyscraper(Vec3f pos, float width, float height, float depth, int roofs): Building(pos)
{
	this->color = { 1.0, 1.0, 1.0 };
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
	this->color = rnd->getRandomColor();
	for (int i = 1; i <= roofs; i++)
	{
		float nWidth = (rnd->getIntFromRange(80/i, 100/i) / 100.0) * width;
		float nHeight = (rnd->getIntFromRange(10*i, 30*i) / 100.0) * height;
		float nDepth = (rnd->getIntFromRange(80/i, 100/i) / 100.0) * depth;

		Vec3f parentPos = getPosition();
		Vec3f nPos = { (width - nWidth) / 2, 0, (depth - nDepth) / 2 };
		BoxBuilding *box = new BoxBuilding(nPos, nWidth, nHeight, nDepth);
		box->setColor(this->color);
		this->addChild(box);
	}
}
