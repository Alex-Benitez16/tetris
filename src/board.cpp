#include "../include/board.h"

Board::Board() : Panel() {
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = 0;
    }
  }
}
