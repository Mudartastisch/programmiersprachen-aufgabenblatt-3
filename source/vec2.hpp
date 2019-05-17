#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 data type definition

struct Vec2
{
    float x;
    float y;
    Vec2();
    Vec2(float a, float b);    
    Vec2(const Vec2& temp);
};

    Vec2 operator+( Vec2 const& u , Vec2 const& v );
    Vec2 operator-( Vec2 const& u , Vec2 const& v );
    Vec2 operator*( Vec2 const& v , float s );
    Vec2 operator*( float s , Vec2 const& v );
    Vec2 operator/( Vec2 const& v , float s );   

# endif // VEC2_HPP