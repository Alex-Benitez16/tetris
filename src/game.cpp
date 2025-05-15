#include "../include/game.h"
#include "raylib.h"

// Constructors and Destructors

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

Game::Game(int _block_size, int _width, int _height, Color _background_color,
           double _fall_speed) {
  current_piece = nullptr;
  next_piece = nullptr;
  held_piece = nullptr;

  renderer = Renderer(_block_size, _width, _height, _background_color);

  Vector2 board_offset = (Vector2){300, 100};
  std::string text = "Puntaje: ";
  board = Board(board_offset, _block_size * GRID_WIDTH,
                _block_size * GRID_HEIGHT, text);

  score = 0;
  game_over = 0;
  fall_speed = _fall_speed;
  timer = 0;
}

Game::~Game() {
  delete current_piece;
  delete next_piece;
  delete held_piece;
}

// Getters and setters

int Game::get_score() { return score; }
bool Game::get_game_over() { return game_over; }
int Game::get_timer() { return timer; }

void Game::draw() {
  BeginDrawing();
  renderer.clear_background();
  renderer.draw_board(board);
  EndDrawing();
}
