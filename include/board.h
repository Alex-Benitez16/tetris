#ifndef BOARD_H
#define BOARD_H

#include "additional.h"
#include "panel.h"
#include "raylib.h"

class Board : public Panel {
private:
  int grid[GRID_HEIGHT][GRID_WIDTH];

public:
  // Constructors and destructors
  Board();
  Board(Vector2 _offset, int _width, int _height, std::string _text);

  // Getters and setters
};

#endif
