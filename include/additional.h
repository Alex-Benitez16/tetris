#ifndef ADDITIONAL_H
#define ADDITIONAL_H

#define GRID_WIDTH 10
#define GRID_HEIGHT 20

#include "raylib.h"

inline bool operator==(const Color &a, const Color &b) {
  return a.r == b.r && a.g == b.g && a.b == b.b && a.a == b.a;
}

inline bool operator!=(const Color &a, const Color &b) { return !(a == b); }

#endif
