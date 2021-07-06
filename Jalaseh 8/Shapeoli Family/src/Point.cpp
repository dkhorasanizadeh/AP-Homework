#include "../include/Point.hpp"

Point::Point(void) {
  x = 0;
  y = 0;
}
Point::Point(float _x, float _y) {
  x = _x;
  y = _y;
}
float Point::operator/(const Point &p) {
  return sqrt(pow((x - p.x), 2) + pow((y - p.y), 2));
}
std::ostream &operator<<(std::ostream &out, Point &p) {
  out << p.x << ":" << p.y;
  return out;
}
std::istream &operator>>(std::istream &in, Point &p) {
  char delimiter;
  in >> p.x >> delimiter >> p.y;
  return in;
}