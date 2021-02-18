#ifndef __BUILDING_H_
#define __BUILDING_H_

#include <vector>
#include "container.hpp"
#include "structs.hpp"

class Building: public Container
{
	protected:
		std::vector<Vec3f> verts;
		std::vector<Triangle> triangles;
	public:
		Building(void);
		Building(Vec3);
		Building(Vec3f);
		~Building();
		void render(void);
};

#endif // __BUILDING_H_
