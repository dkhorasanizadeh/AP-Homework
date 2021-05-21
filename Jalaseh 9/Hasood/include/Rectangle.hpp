#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "Drawable.hpp"
namespace Shape
{
    class Rectangle : public Drawable
    {
    private:
        float Width;
        float Height;

    public:
        Rectangle(COLORREF color, Point center, float width, float height, std::pair<float, float> speed, bool isFilled);
        inline float getWidth(void) { return Width; }
        inline float getHeight(void) { return Height; }
        inline void setWidth(float width) { Width = width; }
        inline void setHeight(float height) { Height = height; }
        void draw(HDC hdc);
        void clear(HDC hdc);
        float getRadius(void);
    };
} // namespace Shape
#endif