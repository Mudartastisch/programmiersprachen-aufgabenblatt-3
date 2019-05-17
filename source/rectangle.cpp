#include "rectangle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include <cmath>
#include <GLFW/glfw3.h>
#include <utility>

Rectangle::Rectangle(){
    min = Vec2(0.0f,0.0f);
    max = Vec2(1.0f,1.0f);
    topLeft = Vec2(min.x, max.y);
    bottomRight = Vec2(max.x, min.y);
    color = Color();
}

Rectangle::Rectangle(Vec2 const& min_, Vec2 const& max_, Color c){
    min = min_;
    max = max_;
    topLeft = Vec2(min.x, max.y);
    bottomRight = Vec2(max.x, min.y);
    color = c;
}


Vec2& Rectangle::getMin(){
    return min;
}

Vec2& Rectangle::getMax(){
    return max;
}


void Rectangle::draw(Window const& win){
    win.draw_line(min.x, min.y, topLeft.x, topLeft.y, color.r, color.g, color.b);
    win.draw_line(topLeft.x, topLeft.y, max.x, max.y, color.r, color.g, color.b);
    win.draw_line(max.x, max.y, bottomRight.x, bottomRight.y, color.r, color.g, color.b);
    win.draw_line(bottomRight.x, bottomRight.y, min.x, min.y, color.r, color.g, color.b);
}

void Rectangle::draw(Window const& win, float thickness){
    win.draw_line(min.x, min.y, topLeft.x, topLeft.y, color.r, color.g, color.b, thickness);
    win.draw_line(topLeft.x, topLeft.y, max.x, max.y, color.r, color.g, color.b, thickness);
    win.draw_line(max.x, max.y, bottomRight.x, bottomRight.y, color.r, color.g, color.b, thickness);
    win.draw_line(bottomRight.x, bottomRight.y, min.x, min.y, color.r, color.g, color.b, thickness);
}

bool Rectangle::is_inside(Vec2 const& test){
	if(min.x <= test.x && test.x <= max.x){
        if(min.y <= test.y && test.y <= max.y) {
		    return true;
    }
        
	} 
	else {
		return false; 
	}
}