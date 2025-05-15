#ifndef RENDERER_H
#define RENDERER_H

#include "board.h"
#include "raylib.h"

class Renderer {
private:
  int block_size;
  int width;
  int height;
  Color background_color;

  // Helper functions

  void draw_board_margin(Board board);
  void draw_board_grid(Board board);

public:
  // Constructors and destructors
  Renderer();
  Renderer(int _block_size, int _width, int _height, Color _background_color);
  ~Renderer();

  // Main functions
  void clear_background();
  void draw_board(Board board);
};

#endif
