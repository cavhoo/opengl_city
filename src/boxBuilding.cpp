#include "boxBuilding.hpp"
#include "building.hpp"
#include "structs.hpp"
#include "vectors.hpp"
#include <GL/gl.h>
#include <stdio.h>

BoxBuilding::BoxBuilding(Vec3f position, float width, float height, float depth): Building(position)
{
	printf("Box Building Constructor\n");
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

Vec3f BoxBuilding::getPosition()
{
	return Building::getPosition();
}

void BoxBuilding::render()
{
	glBegin(GL_TRIANGLES);
	for ( unsigned i = 0; i < this->triangles.size(); i++ )
	{
		Triangle tri = this->triangles[i];
		glVertex3f(tri.a.x, tri.a.y, tri.a.z);
		glVertex3f(tri.b.x, tri.b.y, tri.b.z);
		glVertex3f(tri.c.x, tri.c.y, tri.c.z);
	}
	glEnd();
	Building::render();
}

BoxBuilding::~BoxBuilding()
{

}
