#ifndef __RENDERER_H_
#define __RENDERER_H_

#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glut.h>

int init(int *argc, char **argv, int width, int height);
void render();
void update();

#endif // __RENDERER_H_
