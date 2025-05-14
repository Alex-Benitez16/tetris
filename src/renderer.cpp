#include "../include/Renderer.h"
#include "raylib.h"

Renderer::Renderer() {
  block_size = 0;
  board_offset = (Vector2){0.0, 0.0};
}

Renderer::Renderer(int _block_size, Vector2 _board_offset) {
  block_size = _block_size;
  board_offset = _board_offset;
}
