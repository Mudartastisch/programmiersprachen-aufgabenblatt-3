#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle
{
private:
    Vec2 min;
    Vec2 max;
    Vec2 topLeft;
    Vec2 bottomRight;
    Color color;
public:
    Rectangle();
    Rectangle(Vec2 const& min_, Vec2 const& max_, Color c);

    Vec2& getMin();
    Vec2& getMax();
   
    void draw(Window const& win);
    void draw(Window const& win, float thickness);

    bool is_inside(Vec2 const& test);
};


#endif //RECTANGLE_HPP