#include "../include/renderer.h"
#include "raylib.h"

#include <iostream>

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
}

Renderer::~Renderer() {}

// Getters and setters
int Renderer::get_block_size() { return block_size; }

// Helper functions

void Renderer::draw_board_margin(Board board) {
  Rectangle rec = (Rectangle){
      board.get_offset().x - 6, board.get_offset().y - 6,
      (float)board.get_width() + 12, (float)board.get_height() + 12};
  DrawRectangleLinesEx(rec, 6, RED);
  DrawRectangleLines(board.get_offset().x, board.get_offset().y,
                     board.get_width(), board.get_height(), RAYWHITE);
}

void Renderer::draw_board_grid(Board board) {
  int x = board.get_offset().x;
  int y = board.get_offset().y;
  for (int i = 1; i < GRID_HEIGHT; i++) {
    DrawLine(x, i * block_size + y, x + board.get_width(), i * block_size + y,
             (Color){245, 245, 245, 180});
  }
  for (int i = 1; i < GRID_WIDTH; i++) {
    DrawLine(i * block_size + x, y, i * block_size + x, y + board.get_height(),
             (Color){245, 245, 245, 180});
  }
}

// Main functions

void Renderer::init_window() { InitWindow(width, height, "Tetris"); }
void Renderer::close_window() { CloseWindow(); }

bool Renderer::window_should_close() { return WindowShouldClose(); }

void Renderer::begin_drawing() { BeginDrawing(); }
void Renderer::end_drawing() { EndDrawing(); }

void Renderer::clear_background() { ClearBackground(background_color); }

void Renderer::draw_board(Board board) {
  draw_board_margin(board);
  draw_board_grid(board);
}

void Renderer::draw_piece(Board board) {
  for (int i = 0; i < 4; i++) {
    int posX = board.get_offset().x +
               board.get_piece()->get_positions()[i].x * block_size +
               board.get_piece_position().x * block_size;
    int posY = board.get_offset().y +
               board.get_piece()->get_positions()[i].y * block_size +
               board.get_piece_position().y * block_size;
    DrawRectangle(posX, posY, block_size, block_size,
                  board.get_piece()->get_color());
  }
}
