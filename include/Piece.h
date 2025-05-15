#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"

#ifdef BLANK
#undef BLANK
#endif
#define BLANK                                                                  \
  (Color) { 0, 0, 0, 0 }

class Piece {
protected:
  int shape[3][3];
  Color color;
  Vector2 positions[4];
  char rotation_state;

public:
  Piece();
  Piece(char _shape, Color _color, Vector2 _positions[4]);
};

#endif
