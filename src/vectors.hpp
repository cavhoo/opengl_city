#ifndef __VECTORS_H_
#define __VECTORS_H_

#include <string>
template <class T> class Vector {
  public:
        virtual T* add(T) = 0;
        virtual T* sub(T) = 0;
        virtual T* multiply(T) = 0;
        virtual T* distance(T) = 0;
        virtual std::string toString() = 0;
};

#endif
