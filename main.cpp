#include <stdio.h>

#include "renderer/renderer.h"

int main(int argc, char **argv) {
  int initalized = init(&argc, argv, 800, 600);
  if (initalized != 0) {
    printf("Error initializing OpenGL Rendering");
    return 1;
  }
}
