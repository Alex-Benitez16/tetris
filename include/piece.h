#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"

class Piece {
protected:
  Color color;
  Vector2 positions[4];
  char rotation_state;

public:
  Piece();
  Piece(Color _color, Vector2 _positions[4]);

  Vector2 *get_positions();
  Color get_color();
};

#endif
