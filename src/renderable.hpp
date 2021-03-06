#ifndef __RENDERABLE_H_
#define __RENDERABLE_H_

#include "vectors.hpp"
class Renderable {
	public:
		virtual void render(Vec3f parentPositon) = 0;
};

#endif // __RENDERABLE_H_
