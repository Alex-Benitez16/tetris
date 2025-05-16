#include "../include/piece-o.h"
#include "raylib.h"

// Construcotors and destructors
Piece_o::Piece_o() : Piece(){};

Piece_o::Piece_o(Color _color, Vector2 _positions[4])
    : Piece(_color, _positions) {}
