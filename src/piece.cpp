#include "../include/piece.h"
#include "raylib.h"
#include <random>

Piece::Piece() {
  color = BLANK;
  for (int i = 0; i < 4; i++) {
    positions[i] = (Vector2){0.0, 0.0};
    rotation_state = 0;
    rotation_table[0] = '0';
    rotation_table[1] = 'R';
    rotation_table[2] = '2';
    rotation_table[3] = 'L';
  }
}

Piece::Piece(Color _color, Vector2 _positions[4]) {
  for (int i = 0; i < 4; i++) {
    positions[i] = _positions[i];
  }
  color = _color;
  rotation_state = 0;
  rotation_table[0] = '0';
  rotation_table[1] = 'R';
  rotation_table[2] = '2';
  rotation_table[3] = 'L';
}

Piece::~Piece() {}

bool Piece::has_available_space(Color grid[GRID_HEIGHT][GRID_WIDTH],
                                Vector2 board_position,
                                Vector2 test_positions[4]) {
  int x = board_position.x;
  int y = board_position.y;
  for (int i = 0; i < 4; i++) {
    int piece_x = test_positions[i].x;
    int piece_y = test_positions[i].y;
    if (grid[(int)(y + piece_y)][(int)(x + piece_x)] != BLANK ||
        x + piece_x < 0 || x + piece_x >= GRID_WIDTH ||
        y + piece_y > GRID_HEIGHT) {
      return false;
    }
  }
  return true;
}

Vector2 *Piece::get_positions() { return positions; }

Color Piece::get_color() { return color; }
