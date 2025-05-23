#include "../include/board.h"
#include "../include/game.h"
#include "../include/piece-o.h"
#include "../include/renderer.h"
#include "raylib.h"

#include "../include/additional.h"

#define BLOCK_SIZE 16
#define WIDTH 50
#define HEIGHT 25

int main() {
  int window_width = BLOCK_SIZE * WIDTH;
  int window_height = BLOCK_SIZE * WIDTH;
  double fall_speed = 10.0;
  Vector2 offset = (Vector2){
      (float)((int)(window_width / 2) - GRID_WIDTH * (int)(BLOCK_SIZE / 2)),
      (float)((int)(window_height / 2) - GRID_HEIGHT * (int)(BLOCK_SIZE / 2))};

  Game game(BLOCK_SIZE, window_width, window_height, BLACK, fall_speed, offset);

  game.init();

  game.set_current_piece(new Piece_o());
  // game.set_next_piece(new Piece());
  // game.set_held_piece(new Piece());

  while (!game.get_renderer()->window_should_close()) {
    game.update();
    game.draw();
  }

  game.get_renderer()->close_window();
  return 0;
}
