#ifndef GAME_H
#define GAME_H

#include "additional.h"
#include "board.h"
#include "piece.h"
#include "raylib.h"
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

  int block_size;

  void handle_input();

public:
  // Constructors and destructors
  Game();
  Game(int _block_size, int _width, int _height, Color _background_color,
       double _fall_speed, Vector2 _board_offset);

  ~Game();

  // Getters and setters
  int get_score();
  bool get_game_over();
  int get_timer();

  Renderer *get_renderer();

  void set_current_piece(Piece *_current_piece);
  void set_next_piece(Piece *_next_piece);
  void set_held_piece(Piece *_held_piece);

  void draw();
  void update();
  void init();
};

#endif
