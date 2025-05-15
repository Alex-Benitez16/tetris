#ifndef PANEL_H
#define PANEL_H

#include "raylib.h"
#include <string>

class Panel {
protected:
  Vector2 offset;
  int width;
  int height;
  std::string text;

public:
  Panel();
  Panel(Vector2 _offset, int _width, int _height, std::string _text);
};

#endif
