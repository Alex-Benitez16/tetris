#include "../include/additional.h"
#include "../include/board.h"
#include "../include/game.h"
#include "../include/piece-o.h"
#include "../include/renderer.h"
#include "raylib.h"

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

  Vector2 positions[4] = {(Vector2){0, 0}, (Vector2){1, 0}, (Vector2){1, 1},
                          (Vector2){2, 1}};
  game.set_current_piece(new Piece_o());
  game.set_next_piece(new Piece());
  game.set_held_piece(new Piece());

  while (!game.get_renderer()->window_should_close()) {
    game.update();
    game.draw();
  }

  game.get_renderer()->close_window();
  return 0;
}
