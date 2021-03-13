#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include "cityBlock.hpp"
#include "boxBuilding.hpp"
#include "scene.hpp"
#include "skyscraper.hpp"
#include "vectors.hpp"

float drawingInterval = 0.0;
float rotation = 0.0;
Scene* rootScene;
// Method Stubs
void initRendering(void);
void onResize(int,int);
void setFPS(int);
void scheduleRedraw(int);
void render(void);
void idle(void);
void setupRootScene(void);

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(1024, 768);
  glutCreateWindow("OpenGL City");
  initRendering();
  setupRootScene();
  glutDisplayFunc(render);
  glutReshapeFunc(onResize);
  glutIdleFunc(idle);
  setFPS(30);
  glutMainLoop();
  return 0;
}

void setupRootScene()
{
  rootScene = new Scene("root");

  CityBlock *block = new CityBlock(600, 600);
  block->setPosition({0, 0, 0});
  block->create();
  block->setAnchor({0.5, 0.0, 0.5});
  rootScene->setPosition({0, 0, 0});
  rootScene->addChild(block);
}


void initRendering()
{
  glEnable(GL_DEPTH_TEST);
}

void onResize(int w, int h)
{
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  gluPerspective(45.0, (double) w / (double) h, 1.0, 3500.0);
}

void setFPS(int fps)
{
  drawingInterval = 1000.0f / fps;
  glutTimerFunc((int)drawingInterval, scheduleRedraw, 0);
}

void scheduleRedraw(int v)
{
  glutTimerFunc((int)drawingInterval, scheduleRedraw, v);
}

void idle()
{
  glutPostRedisplay();
}

void render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  // Look at center of grid with a distance of 2000 units
  gluLookAt(0, 600, 2000, 0, 0, 0, 0, 1, 0);

  // Rotate grid constantly
  rotation += 0.5;
  glRotatef(rotation, 0, 1, 0);

  // Render base grid
  glColor3f(1.0, 0.0, 1.0);
  glBegin(GL_LINES);
  for (GLfloat i = -1000.0; i <= 1000.0; i += 10)
  {
    glVertex3f(i, 0, 1000); glVertex3f(i, 0, -1000);
    glVertex3f(1000, 0, i); glVertex3f(-1000, 0, i);
  }
  glEnd();
  // Render Root Scene
  glColor3f(1.0, 1.0, 1.0);
  rootScene->render({0.0, 0.0, 0.0});
  glutSwapBuffers();
}
