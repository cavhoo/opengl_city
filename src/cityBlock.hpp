#ifndef __CITYBLOCK_H_
#define __CITYBLOCK_H_

#include <cstdio>
#include <vector>
#include <vector>
#include "container.hpp"
#include "structs.hpp"
#include "vectors.hpp"
#include "skyscraper.hpp"

class CityBlock: public Container
{
	private:
		int width = 0;
		int depth = 0;
		int alleys = 0;
		int maxBuildings = 5;
		int pavementWidth = 1;
		int roadWidth = 3;
		vector<Renderable *> buildings;
		vector<Renderable *> roads;
	public:
		CityBlock();
		CityBlock(int, int);
		void render(Vector3f);
		void setAlleyCount(int count);
		void create(void);
};


#endif // __CITYBLOCK_H_
