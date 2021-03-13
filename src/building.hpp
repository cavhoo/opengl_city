#ifndef __BUILDING_H_
#define __BUILDING_H_

#include <vector>
#include "container.hpp"
#include "structs.hpp"
#include "vector3.hpp"
#include "vector3f.hpp"

class Building: public Container
{
	protected:
		Color3f color;
		std::vector<Vector3f> verts;
		std::vector<Triangle> triangles;
	public:
		Building(void);
		Building(Vector3);
		Building(Vector3f);
		~Building();
		void setColor(Color3f color);
		void render(Vector3f parentPosition);
};

#endif // __BUILDING_H_
