#include "container.hpp"
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

void Container::render() {
  printf("Rendering %lu children\n ", this->children.size());
  for (unsigned i = 0; i < this->children.size(); i++) {
    this->children[i]->render();
  }
}
