#include <cmath>
#include <iostream>
#ifndef POINT_HPP
#define POINT_HPP
class Point {
 private:
  float x;
  float y;

 public:
  Point(void);
  Point(float _x, float _y);
  float operator/(const Point &p);
  inline float getX(void) { return x; }
  inline float getY(void) { return y; }
  inline void setX(float _x) { x = _x; }
  inline void setY(float _y) { y = _y; }
  friend std::ostream &operator<<(std::ostream &out, Point &p);
  friend std::istream &operator>>(std::istream &in, Point &p);
};
#endif