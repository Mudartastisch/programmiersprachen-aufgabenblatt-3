#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle
{
private:
    Vec2 center;
    float radius;
    Color color;
public:
    Circle();
    Circle(Vec2 v, float r, Color c);

    float getRadius();

    void draw(Window const& win);
    void draw(Window const& win, float thickness);
    void drawClock(Window const& win, float degree);

    bool is_inside(Vec2 const& test);
};

#endif //CIRCLE_HPP