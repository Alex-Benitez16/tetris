#ifndef BOARD_H
#define BOARD_H

#include "additional.h"
#include "panel.h"
#include "raylib.h"

class Board : public Panel {
private:
  int grid[GRID_HEIGHT][GRID_WIDTH];

public:
  Board();
};

#endif
