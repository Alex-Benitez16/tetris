#ifndef PIECE_H
#define PIECE_H

#include "additional.h"
#include "raylib.h"

class Piece {
protected:
  Color color;
  Vector2 positions[4];
  int rotation_state;

  char rotation_table[4];

  virtual void math_rotate_clockwise(Vector2 *array) = 0;
  virtual void math_rotate_counterclockwise(Vector2 *array) = 0;

  bool has_available_space(Color grid[GRID_HEIGHT][GRID_WIDTH],
                           Vector2 board_position, Vector2 test_positions[4]);

public:
  Piece();
  Piece(Color _color, Vector2 _positions[4]);
  virtual ~Piece();

  Vector2 *get_positions();
  Color get_color();

  virtual void rotate_clockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                                Vector2 board_position) = 0;
  virtual void rotate_counterclockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                                       Vector2 board_position) = 0;
};

#endif
