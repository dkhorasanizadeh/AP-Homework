#ifndef SHAPES_HPP
#define SHAPES_HPP
#include <windows.h>

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include "Point.hpp"
namespace Shape {
class Drawable {
 public:
  virtual void move(void);
  virtual void draw(HDC hdc) = 0;
  virtual void clear(HDC hdc) = 0;
  virtual float getRadius(void) = 0;
  virtual Point getCenter(void) { return Center; };
  inline COLORREF getColor(void) { return Color; }
  inline void setColor(COLORREF color) { Color = color; }
  inline void setSpeed(std::pair<float, float> speed) {
    SpeedX = speed.first;
    SpeedY = speed.second;
  }
  inline std::pair<float, float> getSpeed(void) {
    return std::pair<float, float>(SpeedX, SpeedY);
  }
  static Drawable *createObject(int type);

 protected:
  COLORREF Color;
  float SpeedX;
  float SpeedY;
  Point Center;
  bool IsFilled;
};
}  // namespace Shape
#endif