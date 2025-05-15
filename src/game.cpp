#include "../include/game.h"

Game::Game() {
  current_piece = nullptr;
  next_piece = nullptr;
  held_piece = nullptr;

  renderer = Renderer();
  board = Board();

  score = 0;
  game_over = false;
  fall_speed = 10.0;
  timer = 0;
}

Game::Game(int _block_size, int _width, int _height, double _fall_speed) {
  current_piece = nullptr;
  next_piece = nullptr;
  held_piece = nullptr;

  renderer = Renderer(_block_size, _width, _height);
  board = Board();

  score = 0;
  game_over = 0;
  fall_speed = _fall_speed;
  timer = 0;
}
