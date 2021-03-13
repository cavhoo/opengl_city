#ifndef __STRUCTS_H_
#define __STRUCTS_H_

#include "vector3f.hpp"

typedef struct Triangle {
	Vector3f a;
	Vector3f b;
	Vector3f c;
} Triangle;

typedef struct Area {
	Vector3f pos;
	float width;
	float depth;
} Area;

typedef struct Color3f {
	float r;
	float g;
	float b;
} Color3f;

#endif // __STRUCTS_H_
