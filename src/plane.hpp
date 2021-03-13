#ifndef __PLANE_H_
#define __PLANE_H_

#include "renderable.hpp"
#include "structs.hpp"
#include "vectors.hpp"
#include <vector>
class Plane: public Renderable {
	private:
		int width = 0;
		int height = 0;
		std::vector<Vector3f> verts;
		std::vector<Triangle> triangles;
		void init(void);
	public:
		void setSize(int, int);
		void render(Vector3f parentPos);
};

#endif // __PLANE_H_
