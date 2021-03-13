#ifndef __CONTAINER_H_
#define __CONTAINER_H_

#include <vector>
#include <string>
#include "uuid.hpp"
#include "vector3f.hpp"
#include "renderable.hpp"
#include <GL/gl.h>

using namespace std;

class Container: public Renderable {
private:
    string uuid = "";
    string name = "";
    Vector3f position = {0, 0, 0};
    Vector3f anchor = {0, 0, 0};
    vector<Renderable*> children;
public:
    Container();
    Container(string name);
    ~Container();
    Vector3f getPosition();
    bool setPosition(Vector3f);
    Vector3f getAnchor();
    bool setAnchor(Vector3f);
    bool addChild(Container *cnt);
    bool removeChild(Container *cnt);
    bool removeChildAt(int);
    Container getChildAt(int);
    int compare(Container);
    string getUUID();
    bool operator==(const Container &rhs);
    void render(Vector3f parentPositon);
};

#endif // __CONTAINER_H_
