#include "../include/renderer.h"
#include "raylib.h"

Renderer::Renderer() {
  block_size = 16;
  width = 800;
  height = 600;
}

Renderer::Renderer(int _block_size, int _width, int _height) {
  block_size = _block_size;
  width = _width;
  height = _height;
}
