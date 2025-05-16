#ifndef PIECE_O_H
#define PIECE_O_H

#include "piece.h"
#include "raylib.h"

class Piece_o : public Piece {
protected:
public:
  // Constructors and destructors
  Piece_o();
  Piece_o(Color _color, Vector2 _positions[4]);
};

#endif
