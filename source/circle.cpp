#include "circle.hpp"
#include "vec2.hpp"
#include "color.hpp"
#include "mat2.hpp"
#include <cmath>
#include <GLFW/glfw3.h>
#include <utility>

#include <iostream>

Circle::Circle(){
    center = Vec2();
    radius = 1.0f;
    color = Color();
}

Circle::Circle(Vec2 v, float r, Color c){
    center = v;
    radius = r;
    color = c;
}

float Circle::getRadius(){
    return radius;
}

void Circle::draw(Window const& win){
    Vec2 point1 = {center.x, center.y - radius};
    Mat2 rota;
    Vec2 ZP;
    Vec2 OQ;
    Vec2 OZ = {400.0f, 400.0f}; //magic number half of window
    Vec2 point2;
    float degree = 10.0f; //magic number random number of lines to draw circle
    //https://de.serlo.org/44277/beispiel-drehung-um-beliebigen-punkt-z
    for( float a = 0.0; a < 360.0f; a = a + degree ){
        ZP = operator-(point1, OZ);
        rota = make_rotation_mat2(degree * (2 * M_PI / 360));//rad is degree * (2*Pi/360)
        OQ = operator*(ZP, rota); 
        point2 = operator+(OQ, OZ); 
        win.draw_line(point1.x, point1.y, point2.x, point2.y, color.r + (0.05f * a) , color.g, color.b + (0.05f * a));
        point1 = {point2.x, point2.y};
    }    

}

void Circle::draw(Window const& win, float thickness){
    Vec2 point1 = {center.x, center.y - radius};
    Mat2 rota;
    Vec2 ZP;
    Vec2 OQ;
    Vec2 OZ = {400.0f, 400.0f}; //magic number half of window
    Vec2 point2;
    float degree = 10.0f; //magic number random number of lines to draw circle
    //https://de.serlo.org/44277/beispiel-drehung-um-beliebigen-punkt-z
    for( float a = 0.0; a < 360.0f; a = a + degree ){
        ZP = operator-(point1, OZ);
        rota = make_rotation_mat2(degree * (2 * M_PI / 360));//rad is degree * (2*Pi/360)
        OQ = operator*(ZP, rota); 
        point2 = operator+(OQ, OZ); 
        win.draw_line(point1.x, point1.y, point2.x, point2.y, color.r + (0.05f * a) , color.g, color.b + (0.05f * a), thickness);
        point1 = {point2.x, point2.y};
    }    

}

void Circle::drawClock(Window const& win, float degree){
    Vec2 point1 = {center.x, center.y - radius};
    Mat2 rota;
    Vec2 ZP;
    Vec2 OQ;
    Vec2 OZ = {400.0f, 400.0f}; //magic number half of window
    Vec2 point2;
    //https://de.serlo.org/44277/beispiel-drehung-um-beliebigen-punkt-z
        ZP = operator-(point1, OZ);
        rota = make_rotation_mat2(degree * (2 * M_PI / 360));//rad is degree * (2*Pi/360)
        OQ = operator*(ZP, rota); 
        point2 = operator+(OQ, OZ); 
        win.draw_line(center.x, center.y, point2.x, point2.y, color.r, color.g, color.b);

}

bool Circle::is_inside(Vec2 const& test){
	if (pow(test.x-center.x,2)+pow(test.y-center.y,2)<=pow(radius,2)) {
		return true;
	}
	else {
		return false;
	}
}