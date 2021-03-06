#ifndef __BUILDING_H_
#define __BUILDING_H_

#include <vector>
#include "container.hpp"
#include "structs.hpp"
#include "vectors.hpp"

class Building: public Container
{
	protected:
		Color3f color;
		std::vector<Vec3f> verts;
		std::vector<Triangle> triangles;
	public:
		Building(void);
		Building(Vec3);
		Building(Vec3f);
		~Building();
		void setColor(Color3f color);
		void render(Vec3f parentPosition);
};

#endif // __BUILDING_H_
