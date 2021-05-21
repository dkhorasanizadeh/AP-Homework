#include "../include/ScreenSaver.hpp"
void initScreen(int n)
{
    double pi = 2 * acos(0.0);
    HWND myconsole = GetConsoleWindow();
    HDC hdc = GetDC(myconsole);
    std::pair<Shape::Drawable *, int> shapes[n];
    //Pair of Shape/LifeTime
    for (int i = 0; i < n; i++)
    {
        shapes[i].first = Shape::Drawable::createObject(rand() % 2);
        shapes[i].second = (rand() % 20) + 1;
    }
    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            shapes[i].first->draw(hdc);
        }
        Sleep(200);
        for (int i = 0; i < n; i++)
        {
            shapes[i].first->clear(hdc);
            shapes[i].first->move();
            shapes[i].second--;
            if (shapes[i].second == 0)
            {
                delete shapes[i].first;
                shapes[i].first = Shape::Drawable::createObject(rand() % 2);
                shapes[i].second = (rand() % 20) + 1;
                continue;
            }
            for (int j = i; j < n; j++)
            {
                if ((shapes[i].first->getCenter() / shapes[j].first->getCenter()) <= shapes[i].first->getRadius() + shapes[j].first->getRadius())
                {
                    std::pair<float, float> speedI = shapes[i].first->getSpeed();
                    std::pair<float, float> speedJ = shapes[j].first->getSpeed();
                    shapes[i].first->setSpeed(std::pair<float, float>(-speedI.first, -speedI.second));
                    shapes[j].first->setSpeed(std::pair<float, float>(-speedJ.first, -speedJ.second));
                }
            }
        }
    }
}