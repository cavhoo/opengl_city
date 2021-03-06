#ifndef __ROAD_H_
#define __ROAD_H_

#include "container.hpp"
#include "structs.hpp"
#include "vectors.hpp"
#include <vector>
class Road: public Container {
	private:
		int width = 0;
		int height = 0;
		int depth = 0;
		Color3f color;
		std::vector<Vec3f> verts;
		std::vector<Triangle> triangles;
		void init(void);
	public:
		Road();
		Road(int, int, int);
		~Road();
		void render();
};

#endif // __ROAD_H_
