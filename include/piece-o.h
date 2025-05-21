#ifndef PIECE_O_H
#define PIECE_O_H

#include "piece.h"
#include "raylib.h"
#include <map>

class Piece_o : public Piece {
private:
  void math_rotate_clockwise(Vector2 *array) override;
  void math_rotate_counterclockwise(Vector2 *array) override;

  std::map<char, Vector2> offsets;

public:
  // Constructors and destructors
  Piece_o();
  Piece_o(Color _color, Vector2 _positions[4]);

  void rotate_clockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                        Vector2 board_position) override;
  void rotate_counterclockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                               Vector2 board_position) override;
};

#endif
