#include "plane.hpp"
#include <GL/gl.h>

void Plane::setSize(int width, int height)
{
	this->width = width;
	this->height = width;
}

void Plane::render(Vector3f parentPos) {
	glBegin(GL_TRIANGLES);
	for (int i = 0; i < this->triangles.size(); i++)
	{
		Triangle tri = this->triangles[i];
		glVertex3f(tri.a.x + parentPos.x, tri.a.y + parentPos.y, tri.a.z + parentPos.z);
		glVertex3f(tri.b.x + parentPos.x, tri.b.y + parentPos.y, tri.b.z + parentPos.z);
		glVertex3f(tri.c.x + parentPos.x, tri.c.y + parentPos.y, tri.c.z + parentPos.z);
	}
	glEnd();
}
