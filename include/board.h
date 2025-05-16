#ifndef BOARD_H
#define BOARD_H

#include "additional.h"
#include "panel.h"
#include "raylib.h"

class Board : public Panel {
private:
  int grid[GRID_HEIGHT][GRID_WIDTH];
  Vector2 piece_position;

public:
  // Constructors and destructors
  Board();
  Board(Vector2 _offset, int _width, int _height, std::string _text);

  // Getters and setters
  void set_piece_position(Vector2 _piece_position);
  Vector2 get_piece_position();
};

#endif
