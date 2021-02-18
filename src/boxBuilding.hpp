#ifndef __BOXBUILDING_H_
#define __BOXBUILDING_H_

#include "building.hpp"
class BoxBuilding : public Building
{
	private:
		float width;
		float height;
		float depth;
		void init();
	public:
		BoxBuilding(Vec3f position, float width, float height, float depth);
		~BoxBuilding();
		void setStories(int);
		Vec3f getPosition();
		void render(void);
};
#endif // __BOXBUILDING_H_
