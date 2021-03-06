#include "boxBuilding.hpp"

BoxBuilding::BoxBuilding(Vector3f position, float width, float height, float depth): Building(position)
{
	this->width = width;
	this->depth = depth;
	this->height = height;
	this->init();
}

void BoxBuilding::init()
{
	float x = this->getPosition().x;
	float y = this->getPosition().y;
	float z = this->getPosition().z;

	float width = this->width;
	float depth = this->depth;
	float height = this->height;


	this->verts.push_back({ x, y, z}); // A
	this->verts.push_back({ x + width, y, z}); // B
	this->verts.push_back({ x + width, y, z + depth}); // C
	this->verts.push_back({ x, y, z + depth}); // D

	this->verts.push_back({ x, y + height, z}); // E
	this->verts.push_back({ x + width, y + height, z}); // F
	this->verts.push_back({ x + width, y + height, z + depth}); // G
	this->verts.push_back({ x, y + height, z + depth}); // H

	// Let's make some triangles
	//Front A B C
	this->triangles.push_back({
		this->verts[0],
		this->verts[1],
		this->verts[5]
	});

	this->triangles.push_back({
		this->verts[0],
		this->verts[5],
		this->verts[4]
	});

	this->triangles.push_back({
		this->verts[1],
		this->verts[2],
		this->verts[6]
	});

	this->triangles.push_back({
		this->verts[1],
		this->verts[6],
		this->verts[5]
	});

	this->triangles.push_back({
		this->verts[2],
		this->verts[3],
		this->verts[7]
	});

	this->triangles.push_back({
		this->verts[2],
		this->verts[7],
		this->verts[6]
	});

	this->triangles.push_back({
		this->verts[3],
		this->verts[0],
		this->verts[4]
	});

	this->triangles.push_back({
		this->verts[3],
		this->verts[4],
		this->verts[7]
	});

	this->triangles.push_back({
		this->verts[4],
		this->verts[5],
		this->verts[6]
	});

	this->triangles.push_back({
		this->verts[4],
		this->verts[6],
		this->verts[7]
	});

	this->triangles.push_back({
		this->verts[0],
		this->verts[1],
		this->verts[2]
	});

	this->triangles.push_back({
		this->verts[0],
		this->verts[2],
		this->verts[3]
	});
}

Vector3f BoxBuilding::getPosition()
{
	return Building::getPosition();
}

void BoxBuilding::render(Vector3f parentPosition)
{
	glBegin(GL_TRIANGLES);
	glColor3f(this->color.r, this->color.g, this->color.b);
	for ( unsigned i = 0; i < this->triangles.size(); i++ )
	{
		Triangle tri = this->triangles[i];
		glVertex3f(tri.a.x + parentPosition.x, tri.a.y + parentPosition.y, tri.a.z + parentPosition.z);
		glVertex3f(tri.b.x + parentPosition.x, tri.b.y + parentPosition.y, tri.b.z + parentPosition.z);
		glVertex3f(tri.c.x + parentPosition.x, tri.c.y + parentPosition.y, tri.c.z + parentPosition.z);
	}
	glEnd();
	Building::render(this->getPosition());
}

BoxBuilding::~BoxBuilding()
{

}
