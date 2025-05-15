#include "../include/additional.h"
#include "../include/board.h"
#include "../include/game.h"
#include "../include/renderer.h"
#include "raylib.h"

int main() {
  Game game(16, 800, 400, BLACK, 10);

  while (!WindowShouldClose()) {
    game.draw();
  }

  return 0;
}
