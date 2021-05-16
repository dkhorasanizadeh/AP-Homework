/*
--------------------------------------------------
Name    : Triangle
Author  : Danial Khorasanizadeh
Course  : Advanced Programming - Spring 1400
Date    : 05/May/2021
--------------------------------------------------
*/
#include <iostream>

class Triangle
{
public:
    void triangle(void)
    {
        std::cout << "I am a triangle" << std::endl;
    }
};
class Isosceles : public Triangle
{
public:
    void isosceles(void)
    {
        std::cout << "I am an isosceles triangle" << std::endl;
    }
    void description(void)
    {
        std::cout << "In an isosceles triangle two sides are equal" << std::endl;
    }
};
int main()
{
    Isosceles isc;
    isc.isosceles();
    isc.description();
    isc.triangle();
    return 0;
}