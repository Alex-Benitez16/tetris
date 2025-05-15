#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "piece.h"
#include "renderer.h"

class Game {
private:
  Piece *current_piece;
  Piece *next_piece;
  Piece *held_piece;

  Renderer renderer;
  Board board;

  int score;
  bool game_over;
  double fall_speed;
  int timer;

public:
  Game();
  Game(int _block_size, int _width, int _height, double _fall_speed);
};

#endif
