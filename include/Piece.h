#ifndef PIECE_H
#define PIECE_H

#include "raylib.h"

#ifdef BLANK
#undef BLANK
#endif
#define BLANK                                                                  \
  Color { 0, 0, 0, 0 }

class Piece {
private:
  int shape[3][3];
  Color color;
  Vector2 position;
  char rotation_state;

public:
  Piece() {
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        shape[i][j] = 0;
      }
    }
    color = BLANK;
    position = (Vector2){0.0, 0.0};
    rotation_state = '0';
  }

  Piece(char shape_choice, Color color_choice, Vector2 position_choice) {
    if (shape_choice == 'T') {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          shape[i][j] = 0;
        }
      }
      shape[0][1] = 1;
      shape[1][0] = 1;
      shape[1][1] = 1;
      shape[1][2] = 1;
    }
    position = position_choice;
    rotation_state = '0';
  }
};

#endif
