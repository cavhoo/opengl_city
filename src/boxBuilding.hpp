#ifndef __BOXBUILDING_H_
#define __BOXBUILDING_H_

#include <GL/gl.h>
#include <stdio.h>
#include "building.hpp"
#include "structs.hpp"
#include "vector3f.hpp"

class BoxBuilding : public Building
{
	private:
		float width;
		float height;
		float depth;
		void init();
	public:
		BoxBuilding(Vector3f position, float width, float height, float depth);
		~BoxBuilding();
		void setStories(int);
		Vector3f getPosition();
		void render(Vector3f parentPosition);
};
#endif // __BOXBUILDING_H_
