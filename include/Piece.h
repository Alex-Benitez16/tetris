#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"

#ifdef BLANK
#undef BLANK
#endif
#define BLANK                                                                  \
  (Color) { 0, 0, 0, 0 }

class Piece {
private:
  int shape[3][3];
  Color color;
  Vector2 position;
  char rotation_state;

public:
  Piece();
  Piece(char _shape, Color _color, Vector2 _position);
};

#endif
