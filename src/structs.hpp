#ifndef __STRUCTS_H_
#define __STRUCTS_H_

#include "vectors.hpp"

typedef struct Triangle {
	Vec3f a;
	Vec3f b;
	Vec3f c;
} Triangle;

typedef struct Area {
	Vec3f pos;
	float width;
	float depth;
} Area;

typedef struct Color3f {
	float r;
	float g;
	float b;
} Color3f;

#endif // __STRUCTS_H_
