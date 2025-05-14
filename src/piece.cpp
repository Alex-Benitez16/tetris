#include "../include/Piece.h"

Piece::Piece() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      shape[i][j] = 0;
    }
  }
  color = BLANK;
  position = (Vector2){0.0, 0.0};
  rotation_state = '0';
}

Piece::Piece(char _shape, Color _color, Vector2 _position) {
  if (_shape == 'T') {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        shape[i][j] = 0;
      }
    }
    shape[0][1] = 1;
    shape[1][0] = 1;
    shape[1][1] = 1;
    shape[1][2] = 1;
  }
  position = _position;
  rotation_state = '0';
}
