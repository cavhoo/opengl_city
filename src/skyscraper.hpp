#ifndef __SKYSCRAPER_H_
#define __SKYSCRAPER_H_

#include "building.hpp"
#include "vectors.hpp"
#include "boxBuilding.hpp"
#include "randomGenerator.hpp"
#include <cstdlib>
#include <ctime>

class Skyscraper: public Building {
	private:
		float width;
		float height;
		float depth;
		int roofs;
		void init(void);
	public:
		Skyscraper(Vec3f pos, float width, float height, float depth, int roofs);
};
#endif // __SKYSCRAPER_H_
