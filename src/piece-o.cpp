#include "../include/piece-o.h"
#include "raylib.h"

#include "../include/additional.h"

#include <iostream>

// Constructors and destructors
Piece_o::Piece_o()
    : Piece(YELLOW, (Vector2[4]){(Vector2){1, 0}, (Vector2){2, 0},
                                 (Vector2){1, 1}, (Vector2){2, 1}}) {
  offsets['0'] = (Vector2){0, 0};
  offsets['R'] = (Vector2){0, -1};
  offsets['2'] = (Vector2){-1, -2};
  offsets['L'] = (Vector2){-1, 0};
};
void Piece_o::math_rotate_clockwise(Vector2 *array) {
  for (int i = 0; i < 4; i++) {
    int x = positions[i].x;
    int y = positions[i].y;
    array[i] = (Vector2){(float)y, (float)3 - x};
  }
}

void Piece_o::math_rotate_counterclockwise(Vector2 *array) {
  for (int i = 0; i < 4; i++) {
    int x = positions[i].x;
    int y = positions[i].y;
    array[i] = (Vector2){(float)(3 - y), (float)x};
  }
}

void Piece_o::rotate_clockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                               Vector2 board_position) {

  // Calc offsets from rotation positions
  Vector2 offset = offsets[rotation_table[(rotation_state + 1) % 4]] -
                   offsets[rotation_table[rotation_state % 4]];

  // Create a copy of positions named test_positions
  Vector2 test_positions[4];
  for (int i = 0; i < 4; i++) {
    test_positions[i] = positions[i];
  }

  // Rotate piece
  math_rotate_clockwise(test_positions);
  // Add single offset
  for (int i = 0; i < 4; i++) {
    test_positions[i] = test_positions[i] - offset;
  }
  // NOTE: use function is_available_space or whatever
  // also perhaps divide in more functions

  // If there is available space, update positions
  if (has_available_space(grid, board_position, test_positions)) {
    for (int i = 0; i < 4; i++) {
      positions[i] = test_positions[i];
    }
    rotation_state++;
  }
}

void Piece_o::rotate_counterclockwise(Color grid[GRID_HEIGHT][GRID_WIDTH],
                                      Vector2 board_position) {

  // Calc offsets from rotation positions
  Vector2 offset = offsets[rotation_table[(rotation_state - 1) % 4]] -
                   offsets[rotation_table[rotation_state % 4]];

  // Create a copy of positions named test_positions
  Vector2 test_positions[4];
  for (int i = 0; i < 4; i++) {
    test_positions[i] = positions[i];
  }

  // Rotate piece
  math_rotate_counterclockwise(test_positions);
  // Add single offset
  for (int i = 0; i < 4; i++) {
    test_positions[i] = test_positions[i] - offset;
  }

  // If there is available space, update positions
  if (has_available_space(grid, board_position, test_positions)) {
    for (int i = 0; i < 4; i++) {
      positions[i] = test_positions[i];
    }
    rotation_state--;
  }
}
