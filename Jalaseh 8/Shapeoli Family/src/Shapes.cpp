#include "../include/Shapes.hpp"
Point Shape::getCenter(void) {
  float sum = 0;
  for (int i = 0; i < Points.size(); i++) {
    sum += Points[i].getX();
  }
  float centerX = sum / Points.size();
  sum = 0;
  for (int i = 0; i < Points.size(); i++) {
    sum += Points[i].getY();
  }
  float centerY = sum / Points.size();
  Point Center(centerX, centerY);
  return Center;
}
Triangle::Triangle(std::string color, std::vector<Point> points) {
  Color = color;
  Points = points;
}
float Triangle::getArea(void) {
  float area;
  area += Points[0].getX() * Points[1].getY();
  area += Points[1].getX() * Points[2].getY();
  area += Points[2].getX() * Points[0].getY();
  area -= Points[0].getY() * Points[1].getX();
  area -= Points[1].getY() * Points[2].getX();
  area -= Points[2].getY() * Points[0].getX();
  area = abs(area) / 2;
  return area;
}
float Triangle::getPerimeter(void) {
  float perimeter = 0;
  perimeter += Points[0] / Points[1];
  perimeter += Points[1] / Points[2];
  perimeter += Points[0] / Points[2];
  return perimeter;
}
Rectangle::Rectangle(std::string color, std::vector<Point> points) {
  assert((points[0] / points[1]) == (points[2] / points[3]));
  assert((points[0] / points[3]) == (points[1] / points[2]));
  Color = color;
  Points = points;
}
float Rectangle::getArea(void) {
  float width = Points[1] / Points[2];
  float height = Points[0] / Points[1];
  float area = width * height;
  return area;
}
float Rectangle::getPerimeter(void) {
  float width = Points[1] / Points[2];
  float height = Points[0] / Points[1];
  float perimeter = 2 * (width + height);
  return perimeter;
}
Square::Square(std::string color, std::vector<Point> points) {
  float distance = points[0] / points[1];
  for (int i = 1; i < points.size() - 1; i++) {
    assert((points[i] / points[i + 1]) == distance);
  }
  Color = color;
  Points = points;
}
float Square::getArea(void) {
  float side = Points[0] / Points[1];
  float area = side * side;
  return area;
}
float Square::getPerimeter(void) {
  float distance = Points[0] / Points[1];
  return 4 * distance;
}
Rhombus::Rhombus(std::string color, std::vector<Point> points) {
  float distance = points[0] / points[1];
  for (int i = 1; i < points.size() - 1; i++) {
    assert((points[i] / points[i + 1]) == distance);
  }
  Color = color;
  Points = points;
}
float Rhombus::getArea(void) {
  float p = Points[0] / Points[2];
  float q = Points[1] / Points[3];
  float area = (p * q) / 2;
  return area;
}
float Rhombus::getPerimeter(void) {
  float distance = Points[0] / Points[1];
  return 4 * distance;
}
Circle::Circle(std::string color, std::vector<Point> points, float radius) {
  Color = color;
  Points = points;
  Radius = radius;
}
float Circle::getArea(void) { return 3.141592 * pow(Radius, 2); }
float Circle::getPerimeter(void) { return 2 * 3.141592 * Radius; }
