#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"

class Renderer {
private:
  int block_size;
  int width;
  int height;

public:
  Renderer();
  Renderer(int _block_size, int _width, int _height);
};

#endif
