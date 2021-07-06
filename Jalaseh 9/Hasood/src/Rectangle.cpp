#include "../include/Rectangle.hpp"
namespace Shape {
Rectangle::Rectangle(COLORREF color, Point center, float width, float height,
                     std::pair<float, float> speed, bool isFilled) {
  Color = color;
  Center = center;
  Width = width;
  Height = height;
  SpeedX = speed.first;
  SpeedY = speed.second;
  IsFilled = isFilled;
}
void Rectangle::draw(HDC hdc) {
  for (int i = -Width / 2; i < Width / 2; i++) {
    SetPixel(hdc, Center.getX() + i, Center.getY() - Height / 2, Color);
    SetPixel(hdc, Center.getX() + i, Center.getY() + Height / 2, Color);
  }
  for (int j = -Height / 2; j < Height / 2; j++) {
    SetPixel(hdc, Center.getX() - Width / 2, Center.getY() + j, Color);
    SetPixel(hdc, Center.getX() + Width / 2, Center.getY() + j, Color);
  }
  if (IsFilled) {
    for (int i = -Width / 2; i < Width / 2; i++) {
      for (int j = -Height / 2; j < Height / 2; j++) {
        SetPixel(hdc, Center.getX() + i, Center.getY() + j, Color);
      }
    }
  }
}
void Rectangle::clear(HDC hdc) {
  COLORREF black = RGB(0, 0, 0);
  for (int i = -Width / 2; i < Width / 2; i++) {
    SetPixel(hdc, Center.getX() + i, Center.getY() - Height / 2, black);
    SetPixel(hdc, Center.getX() + i, Center.getY() + Height / 2, black);
  }
  for (int j = -Height / 2; j < Height / 2; j++) {
    SetPixel(hdc, Center.getX() - Width / 2, Center.getY() + j, black);
    SetPixel(hdc, Center.getX() + Width / 2, Center.getY() + j, black);
  }
  if (IsFilled) {
    for (int i = -Width / 2; i < Width / 2; i++) {
      for (int j = -Height / 2; j < Height / 2; j++) {
        SetPixel(hdc, Center.getX() + i, Center.getY() + j, black);
      }
    }
  }
}
float Rectangle::getRadius(void) {
  return sqrt(pow(Height / 2, 2) + pow(Width / 2, 2));
}
}  // namespace Shape