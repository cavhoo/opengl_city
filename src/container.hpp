#ifndef __CONTAINER_H_
#define __CONTAINER_H_

#include "uuid.hpp"
#include "vectors.hpp"
#include <string>
#include <vector>
#include "renderable.hpp"

using namespace std;

class Container: public Renderable {
private:
  string uuid = "";
  string name = "";
  Vec3f position = {0, 0, 0};
  vector<Renderable*> children;
public:
  Container();
  Container(string name);
  ~Container();
  Vec3f getPosition();
  bool setPosition(Vec3f);
  bool addChild(Container *cnt);
  bool removeChild(Container *cnt);
  bool removeChildAt(int);
  Container getChildAt(int);
  int compare(Container);
  string getUUID();
  bool operator==(const Container &rhs);
  void render(Vec3f parentPositon);
};

#endif // __CONTAINER_H_
