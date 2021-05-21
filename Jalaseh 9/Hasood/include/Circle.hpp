#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "Drawable.hpp"
namespace Shape
{
    class Circle : public Drawable
    {
    private:
        float Radius;

    public:
        Circle(COLORREF color, Point center, float radius, std::pair<float, float> speed, bool isFilled);
        inline float getRadius(void) { return Radius; }
        inline void setRadius(float radius) { Radius = radius; }
        void draw(HDC hdc);
        void clear(HDC hdc);
    };
} // namespace Shape
#endif