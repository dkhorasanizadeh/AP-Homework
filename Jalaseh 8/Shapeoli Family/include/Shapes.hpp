#include <cassert>
#include <string>
#include <tuple>
#include <vector>

#include "Point.hpp"
#ifndef SHAPES_HPP
#define SHAPES_HPP
class Shape {
 public:
  virtual float getArea(void) = 0;
  virtual float getPerimeter(void) = 0;
  virtual Point getCenter(void);
  inline std::string getColor(void) { return Color; }
  inline void setColor(std::string color) { Color = color; }
  inline Point getPoint(int index) { return Points[index]; }

 protected:
  std::string Color;
  std::vector<Point> Points;
};
class Triangle : public Shape {
 public:
  Triangle(std::string color, std::vector<Point> points);
  float getArea(void);
  float getPerimeter(void);
};
class Rectangle : public Shape {
 public:
  Rectangle(std::string color, std::vector<Point> points);
  float getArea(void);
  float getPerimeter(void);
};
class Square : public Shape {
 public:
  Square(std::string color, std::vector<Point> points);
  float getArea(void);
  float getPerimeter(void);
};
class Rhombus : public Shape {
 public:
  Rhombus(std::string color, std::vector<Point> points);
  float getArea(void);
  float getPerimeter(void);
};
class Circle : public Shape {
 private:
  float Radius;

 public:
  Circle(std::string color, std::vector<Point> points, float radius);
  float getArea(void);
  float getPerimeter(void);
  inline Point getCenter(void) { return Points[0]; }
  inline void setCenter(Point center) { Points[0] = center; }
  inline float getRadius(void) { return Radius; }
  inline void setRadius(float radius) { Radius = radius; }
};
#endif