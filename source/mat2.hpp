#ifndef MAT2_HPP
#define MAT2_HPP
 
# include <array>
# include "vec2.hpp"

struct Mat2 { 

float e_00; // matrix layout :
float e_01; //  e_00 e_01
float e_10; //  e_10 e_11
float e_11;

Mat2(float aa = 1.0f, float ab = 0.0f, float ba = 0.0f, float bb = 1.0f):e_00(aa), e_01(ab), e_10(ba), e_11(bb) {}
float det() const;

// TODO (in mat2.cpp) Definition v.operator *=
Mat2& operator*=( Mat2 const& m );
};

// TODO(in mat2.cpp) Definition v.operator *
Mat2 operator*( Mat2 const& m1 , Mat2 const& m2 );

Vec2 operator*( Mat2 const& m , Vec2 const& v );
Vec2 operator*( Vec2 const& v , Mat2 const& m );

Mat2 inverse(Mat2 const& m );
Mat2 transpose ( Mat2 const & m );
Mat2 make_rotation_mat2 ( float phi );

#endif //MAT2_HPP