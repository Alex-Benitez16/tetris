#include "../include/renderer.h"
#include "raylib.h"

// Constructors and destructors
Renderer::Renderer() {
  block_size = 16;
  width = 800;
  height = 600;
  background_color = RAYWHITE;
}

Renderer::Renderer(int _block_size, int _width, int _height,
                   Color _background_color) {
  block_size = _block_size;
  width = _width;
  height = _height;
  background_color = _background_color;
  InitWindow(_width, _height, "Tetris");
}

Renderer::~Renderer() { CloseWindow(); }

// Helper functions

void Renderer::draw_board_margin(Board board) {
  Rectangle rec =
      (Rectangle){board.get_offset().x, board.get_offset().y,
                  (float)board.get_width(), (float)board.get_height()};
  DrawRectangleLinesEx(rec, 3, RAYWHITE);
}

void Renderer::draw_board_grid(Board board) {
  for (int i = 0; i < GRID_HEIGHT; i++) {
    DrawLine(board.get_offset().x, i * block_size, board.get_offset().x + width,
             i * block_size, (Color){245, 245, 245, 180});
  }
  for (int i = 0; i < GRID_WIDTH; i++) {
    DrawLine(i * block_size, board.get_offset().y, i * block_size,
             board.get_offset().y + height, (Color){245, 245, 245, 180});
  }
}

// Main functions

void Renderer::clear_background() { ClearBackground(background_color); }

void Renderer::draw_board(Board board) {
  draw_board_grid(board);
  draw_board_margin(board);
}
