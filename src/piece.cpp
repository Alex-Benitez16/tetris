#include "../include/piece.h"

Piece::Piece() {
  color = BLANK;
  for (int i = 0; i < 4; i++) {
    positions[i] = (Vector2){0.0, 0.0};
    rotation_state = '0';
  }
}

Piece::Piece(char _shape, Color _color, Vector2 _positions[4]) {
  for (int i = 0; i < 4; i++) {
    positions[i] = _positions[i];
  }
  color = _color;
  rotation_state = '0';
}
