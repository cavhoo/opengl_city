#ifndef __VECTOR3_H_
#define __VECTOR3_H_

#include "vectors.hpp"

class Vector3: public Vector<Vector3> {
  public:
        float x;
        float y;
		float z;
        Vector3();
        Vector3(int, int, int);
        Vector3 * add(Vector3) override;
        Vector3 * sub(Vector3) override;
        Vector3 * distance(Vector3) override;
        Vector3 * multiply(Vector3) override;
        std::string toString() override;
};

#endif // __VECTOR3_H_
