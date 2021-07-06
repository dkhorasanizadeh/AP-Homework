#include "../include/Circle.hpp"
namespace Shape {
Circle::Circle(COLORREF color, Point center, float radius,
               std::pair<float, float> speed, bool isFilled) {
  Color = color;
  Center = center;
  Radius = radius;
  SpeedX = speed.first;
  SpeedY = speed.second;
  IsFilled = isFilled;
}
void Circle::draw(HDC hdc) {
  double PI = 2 * acos(0.0);
  for (double theta = 0; theta < 2 * PI; theta += .001) {
    SetPixel(hdc, Center.getX() - Radius * cos(theta),
             Center.getY() - Radius * sin(theta), Color);
  }
  if (IsFilled) {
    int r2 = Radius * Radius;
    for (int i = -Radius; i < Radius; i++) {
      for (int j = -Radius; j < Radius; j++) {
        if (i * i + j * j < r2)
          SetPixel(hdc, Center.getX() - i, Center.getY() - j, Color);
      }
    }
  }
}
void Circle::clear(HDC hdc) {
  double PI = 2 * acos(0.0);
  COLORREF black = RGB(0, 0, 0);
  for (double theta = 0; theta < 2 * PI; theta += .001) {
    SetPixel(hdc, Center.getX() - Radius * cos(theta),
             Center.getY() - Radius * sin(theta), black);
  }
  if (IsFilled) {
    int r2 = Radius * Radius;
    for (int i = -Radius; i < Radius; i++) {
      for (int j = -Radius; j < Radius; j++) {
        if (i * i + j * j < r2)
          SetPixel(hdc, Center.getX() - i, Center.getY() - j, black);
      }
    }
  }
}
}  // namespace Shape