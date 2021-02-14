#include "renderer.h"

int init(int *argc, char **argv, int width, int height) {
  glutInit(argc, argv);
  glutInitDisplayMode(GLUT_SINGLE);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(100, 100);
  int windowCreated = glutCreateWindow("OpenGL City");

  if (windowCreated != 0) {
    return windowCreated;
  }

  glutDisplayFunc(render);
  glutMainLoop();
  return 0;
};

void render() {
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glVertex3f(0.0, 0.0, 0.0);
  glVertex3f(0.5, 0.0, 0.0);
  glVertex3f(0.5, 0.5, 0.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glFlush();
}
