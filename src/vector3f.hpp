#ifndef __VECTOR3F_H_
#define __VECTOR3F_H_

#include "vectors.hpp"
#include <string>

class Vector3f: public Vector<Vector3f> {
  public:
        float x;
        float y;
        float z;
        Vector3f();
        Vector3f(float, float, float);
        Vector3f * add(Vector3f) override;
        Vector3f * sub(Vector3f) override;
        Vector3f * multiply(Vector3f) override;
        Vector3f * distance(Vector3f) override;
        std::string toString() override;
};

#endif // __VECTOR3F_H_
