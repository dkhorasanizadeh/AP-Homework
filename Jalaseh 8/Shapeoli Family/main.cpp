/*
--------------------------------------------------
Name    : Shapoli Family
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 11/May/2021
--------------------------------------------------
*/
#include <iostream>
#include <vector>
#include <iomanip>
#include "include/Point.hpp"
#include "include/Shapes.hpp"
int main(void)
{
    std::cout << std::setprecision(2) << std::fixed;
    int numberOfShapes, shape;
    std::vector<int> shapeTypes;
    std::vector<Shape *> shapes;
    std::cin >> numberOfShapes;
    for (int i = 0; i < numberOfShapes; i++)
    {
        std::cin >> shape;
        shapeTypes.push_back(shape);
    }
    for (int i = 0; i < numberOfShapes; i++)
    {
        if (shapeTypes[i] == 1)
        {
            std::string color;
            std::vector<Point> points;
            Point point;
            char dump;
            std::cin >> color >> dump;
            for (int i = 0; i < 3; i++)
            {
                std::cin >> point;
                points.push_back(point);
            }
            Triangle *t = new Triangle(color, points);
            shapes.push_back(t);
        }
        else if (shapeTypes[i] == 2)
        {
            std::string color;
            std::vector<Point> points;
            Point point;
            char dump;
            std::cin >> color >> dump;
            for (int i = 0; i < 4; i++)
            {
                std::cin >> point;
                points.push_back(point);
            }
            Rectangle *r = new Rectangle(color, points);
            shapes.push_back(r);
        }
        if (shapeTypes[i] == 3)
        {
            std::string color;
            std::vector<Point> points;
            Point point;
            char dump;
            std::cin >> color >> dump;
            for (int i = 0; i < 4; i++)
            {
                std::cin >> point;
                points.push_back(point);
            }
            Rhombus *r = new Rhombus(color, points);
            shapes.push_back(r);
        }
        if (shapeTypes[i] == 4)
        {
            std::string color;
            std::vector<Point> points;
            Point point;
            char dump;
            std::cin >> color >> dump;
            for (int i = 0; i < 4; i++)
            {
                std::cin >> point;
                points.push_back(point);
            }
            Square *s = new Square(color, points);
            shapes.push_back(s);
        }
        if (shapeTypes[i] == 5)
        {
            std::string color;
            Point center;
            std::vector<Point> points;
            float radius;
            char dump;
            std::cin >> color >> dump >> center >> radius;
            points.push_back(center);
            Circle *c = new Circle(color, points, radius);
            shapes.push_back(c);
        }
    }
    for (int i = 0; i < numberOfShapes; i++)
    {
        Point center = shapes[i]->getCenter();
        std::cout << shapes[i]->getColor() << " : " << shapes[i]->getPerimeter() << " " << shapes[i]->getArea() << " " << center << std::endl;
    }
    return 0;
}