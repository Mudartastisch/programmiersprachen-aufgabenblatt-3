#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"
#include <string>

using namespace std; 


class Circle
{
private:
    Vec2 center;
    float radius;
    Color color;
    string name;
public:
    Circle(Vec2 const& c, float i, Color const& cl, string n):center(c), radius(i), color(cl), name(n) {}

    float getRadius() const;
    string getName() const;
    void setColor(Color const & c);
    bool operator<(const Circle& crc) const;
    bool operator>(const Circle& crc) const;
    bool operator==(const Circle& crc) const;

    void debug();

    void draw(Window const& win);
    void draw(Window const& win, float thickness);
    void drawClock(Window const& win, float degree);

    bool is_inside(Vec2 const& test);
};

#endif //CIRCLE_HPP