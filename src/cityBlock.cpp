#include "cityBlock.hpp"
#include "skyscraper.hpp"
#include "structs.hpp"
#include "vectors.hpp"
#include <cstdio>
#include <vector>

CityBlock::CityBlock(): Container()
{
	this->setPosition({0, 0, 0}); // Base Position is Center at origin
	this->width = 100;
	this->depth = 100;
}

CityBlock::CityBlock(int width, int depth)
{
	this->setPosition({0, 0, 0});
	this->width = width;
	this->depth = depth;
}

void CityBlock::setAlleyCount(int count)
{
	if (count > 0)
	{
		alleys = count;
	}
}

void CityBlock::create()
{
	float buildingWidth = this->width / 3.0;
	float buildingDepth = this->depth / 3.0;

	for (int i = 0; i < 9; i++)
	{
		if (i == 4) continue;
		Vec3f pos = { (i % 3) * buildingWidth, 0, ( i / 3 ) * buildingDepth};
		Skyscraper *building = new Skyscraper(pos, buildingWidth, 250.0, buildingDepth, 4 );
		this->buildings.push_back(building);
		this->addChild(building);
	}
}

