#include "cityBlock.hpp"
#include "vectors.hpp"
#include <cstdio>


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
	int pavementRoadWidth = (this->pavementWidth + this->roadWidth) * 2;
	float buildingWidth = (this->width - (pavementRoadWidth)) / 3.0;
	float buildingDepth = (this->depth - (pavementRoadWidth)) / 3.0;

	for (int i = 0; i < 9; i++)
	{
		if (i == 4) continue;
		Vector3f pos = { (i % 3) * buildingWidth, 0, ( i / 3 ) * buildingDepth};
		Skyscraper *building = new Skyscraper(pos, buildingWidth, 250.0, buildingDepth, 4 );
		this->buildings.push_back(building);
		this->addChild(building);
	}

	// RoadPavement Left

	// RoadPavement Right
	// RoadPavement Top
	// RoadPavement Bottom
}

void CityBlock::render(Vector3f parentPos)
{
	float newX = this->getPosition().x - ( this->width * this->getAnchor().x );
	float newY = this->getPosition().y - ( 0 * this->getAnchor().y );
	float newZ = this->getPosition().z - ( this->depth * this->getAnchor().z );
	Container::render({newX + parentPos.x, newY + parentPos.y, newZ + parentPos.z});
}
