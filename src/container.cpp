#include "container.hpp"
#include "vectors.hpp"
#include <GL/gl.h>
#include <cstdio>

Container::Container() {
  this->position.x = 0;
  this->position.y = 0;
  this->position.z = 0;
  this->uuid = get_uuid();
}

Container::Container(string name) : Container() { this->name = name; }

Container::~Container() {}

Vec3f Container::getPosition() { return this->position; }

bool Container::setPosition(Vec3f position) {
  this->position.x = position.x;
  this->position.y = position.y;
  this->position.z = position.z;

  return true;
}

Vec3f Container::getAnchor()
{
  return this->anchor;
}

bool Container::setAnchor(Vec3f anchor)
{
  if (anchor.x > 0 &&  anchor.y > 0 && anchor.z > 0) {
    this->anchor = anchor;
    return true;
  }
  return false;
}

bool Container::addChild(Container *child) {
  this->children.push_back(child);
  return true;
}

bool Container::removeChildAt(int index) {
  this->children.erase(this->children.begin() + index);
  return true;
}

bool Container::removeChild(Container *child) {
  int indexToErase = -1;
  for (unsigned i = 0; i < this->children.size(); i++) {
    if (this->children[i] == child) {
      indexToErase = i;
      break;
    }
  }
  this->removeChildAt(indexToErase);
  return true;
}

int Container::compare(Container other) {
  if (this->uuid == other.uuid) {
    return 0;
  }
  return -1;
}

string Container::getUUID() { return this->uuid; }

bool Container::operator==(const Container &rhs) {
  return this->uuid == rhs.uuid;
}

void Container::render(Vec3f parentPosition) {
  for (unsigned i = 0; i < this->children.size(); i++) {
    this->children[i]->render({
      parentPosition.x + (this->getPosition().x - ( this->getPosition().x * this->anchor.x )),
      parentPosition.y + (this->getPosition().y - ( this->getPosition().y * this->anchor.y )),
      parentPosition.z + (this->getPosition().z - ( this->getPosition().z * this->anchor.z ))
    });
  }
}
