#ifndef __RENDERABLE_H_
#define __RENDERABLE_H_

#include "vector3f.hpp"

class Renderable {
	public:
		virtual void render(Vector3f parentPositon) = 0;
};

#endif // __RENDERABLE_H_
