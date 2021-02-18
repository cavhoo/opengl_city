#include <GL/freeglut_std.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#include "boxBuilding.hpp"
#include "scene.hpp"
#include "vectors.hpp"

float drawingInterval = 0.0;
int rotation = 0;
Scene* rootScene;
// Method Stubs
void initRendering(void);
void onResize(int,int);
void setFPS(int);
void scheduleRedraw(int);
void render(void);
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
  setFPS(30);
  glutMainLoop();
  return 0;
}

void setupRootScene()
{
  rootScene = new Scene("root");
  Vec3f pos = { 50, 0, 50};
  BoxBuilding *box = new BoxBuilding(pos, 100, 300, 100);

  rootScene->addChild(box);
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

void render()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0, 600, 2500, 0, 0, 0, 0, 1, 0);
  glRotatef((GLfloat)++rotation, 0, 1, 0);
  glColor3f(1.0, 1.0, 1.0);
  glBegin(GL_LINES);
  for (GLfloat i = -1000.0; i <= 1000.0; i += 10)
  {
    glVertex3f(i, 0, 1000); glVertex3f(i, 0, -1000);
    glVertex3f(1000, 0, i); glVertex3f(-1000, 0, i);
  }

  // Render Root Scene
  rootScene->render();
  glFlush();
  glutSwapBuffers();
}
