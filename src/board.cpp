#include "../include/board.h"
#include "raylib.h"

Board::Board() : Panel() {
  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = 0;
    }
  }
  piece_position = (Vector2){0.0, 0.0};
}

Board::Board(Vector2 _offset, int _width, int _height, std::string _text)
    : Panel(_offset, _width, _height, _text) {

  for (int i = 0; i < GRID_HEIGHT; i++) {
    for (int j = 0; j < GRID_WIDTH; j++) {
      grid[i][j] = 0;
    }
  }
  piece_position = (Vector2){0.0, 0.0};
};

void Board::set_piece_position(Vector2 _piece_position) {
  piece_position = _piece_position;
}

Vector2 Board::get_piece_position() { return piece_position; }
