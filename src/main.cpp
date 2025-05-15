#include "../include/additional.h"
#include "../include/board.h"
#include "../include/game.h"
#include "../include/renderer.h"
#include "raylib.h"

int main() {
  Game game(16, 800, 400, BLACK, 10);
  game.set_current_piece(new Piece());
  game.set_next_piece(new Piece());
  game.set_held_piece(new Piece());

  game.get_renderer()->init_window();

  while (!game.get_renderer()->window_should_close()) {
    game.draw();
  }

  game.get_renderer()->close_window();
  return 0;
}
