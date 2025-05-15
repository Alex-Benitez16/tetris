#ifndef GAME_H
#define GAME_H

#include "additional.h"
#include "board.h"
#include "piece.h"
#include "renderer.h"
#include <string>

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
  // Constructors and destructors
  Game();
  Game(int _block_size, int _width, int _height, Color _background_color,
       double _fall_speed);

  ~Game();

  // Getters and setters
  int get_score();
  bool get_game_over();
  int get_timer();

  void draw();
};

#endif
