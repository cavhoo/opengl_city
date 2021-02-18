#ifndef __VECTORS_H_
#define __VECTORS_H_

typedef struct Vec2 {
  int x;
  int y;
} Vec2;

typedef struct Vec2f {
  float x;
  float y;
} Vec2f;

typedef struct Vec3 {
  Vec3(){};
  Vec3(int x, int y, int z) {
    this->x = x;
    this->y = y;
    this->z = z;
  };
  int x;
  int y;
  int z;
} Vec3;

typedef struct Vec3f {
  float x;
  float y;
  float z;
} Vec3f;

#endif
