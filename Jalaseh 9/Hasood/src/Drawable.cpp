#include "../include/Drawable.hpp"
#include "../include/Circle.hpp"
#include "../include/Rectangle.hpp"
namespace Shape
{
    Drawable *Drawable::createObject(int type)
    {
        switch (type)
        {
        case 0:
            return new Rectangle(RGB(rand() % 256, rand() % 256, rand() % 256),
                                 Point(rand() % 500, rand() % 500),
                                 rand() % 25,
                                 rand() % 25,
                                 std::pair<float, float>(rand() % 10, rand() % 10), rand() % 2);
            break;
        case 1:
            return new Circle(RGB(rand() % 256, rand() % 256, rand() % 256),
                              Point(rand() % 250, rand() % 250),
                              rand() % 25,
                              std::pair<float, float>(rand() % 10, rand() % 10), rand() % 2);
        default:
            break;
        }
        return nullptr;
    }
    void Drawable::move(void)
    {
        if (Center.getX() > 500)
        {
            SpeedX = -SpeedX;
        }
        if (Center.getY() > 500)
        {
            SpeedY = -SpeedY;
        }
        Center.move(std::pair<float, float>(SpeedX, SpeedY));
    }
} // namespace Shape