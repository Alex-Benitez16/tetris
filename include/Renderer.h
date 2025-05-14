#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"

class Renderer {
private:
  int block_size;
  Vector2 board_offset;

public:
  Renderer();
  Renderer(int _block_size, Vector2 _board_offset);
};

#endif
