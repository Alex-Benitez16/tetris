#ifndef PANEL_H
#define PANEL_H

#include "raylib.h"
#include <string>

#include "additional.h"

class Panel {
protected:
  Vector2 offset;
  int width;
  int height;
  std::string text;

public:
  // Constructors and destructors
  Panel();
  Panel(Vector2 _offset, int _width, int _height, std::string _text);
  virtual ~Panel();

  // Getters and setters
  Vector2 get_offset();
  int get_width();
  int get_height();
  std::string get_text();
};

#endif
