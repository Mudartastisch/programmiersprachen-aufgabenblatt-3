#include "mat2.hpp"
#include <cmath>

Mat2::Mat2(){
    e_00 = 1.0f;
    e_01 = 0.0f;
    e_10 = 0.0f;
    e_11 = 1.0f;
};

Mat2::Mat2(float aa, float ab, float ba, float bb){
    e_00 = aa;
    e_01 = ab;
    e_10 = ba;
    e_11 = bb;
};

Mat2& Mat2::operator*=(Mat2 const& m){
    float temp_e_00 = e_00 * m.e_00 + e_01 * m.e_10;
    float temp_e_01 = e_00 * m.e_01 + e_01 * m.e_11;
    float temp_e_10 = e_10 * m.e_00 + e_10 * m.e_10;
    float temp_e_11 = e_10 * m.e_01 + e_11 * m.e_11;
    e_00 = temp_e_00;
    e_01 = temp_e_01;
    e_10 = temp_e_10;
    e_11 = temp_e_11;
}

Mat2 operator*( Mat2 const& m1 , Mat2 const& m2 ){
    float temp_e_00 = m1.e_00 * m2.e_00 + m1.e_01 * m2.e_10;
    float temp_e_01 = m1.e_00 * m2.e_01 + m1.e_01 * m2.e_11;
    float temp_e_10 = m1.e_10 * m2.e_00 + m1.e_10 * m2.e_10;
    float temp_e_11 = m1.e_10 * m2.e_01 + m1.e_11 * m2.e_11;
    Mat2 temp{temp_e_00, temp_e_01, temp_e_10, temp_e_11};
    return temp;
}

float Mat2::det() const{
    return (e_00 * e_11 - e_01 * e_10);
}

Vec2 operator*( Mat2 const& m , Vec2 const& v ){
    float temp_x = m.e_00 * v.x + m.e_01 * v.y;
    float temp_y = m.e_10 * v.x + m.e_11 * v.y ;
    Vec2 temp{temp_x, temp_y};
    return temp;
}

Vec2 operator*(Vec2 const& v,  Mat2 const& m){
    float temp_x = m.e_00 * v.x + m.e_01 * v.y;
    float temp_y = m.e_10 * v.x + m.e_11 * v.y ;
    Vec2 temp{temp_x, temp_y};
    return temp;
}

Mat2 inverse(Mat2 const& m){
    float temp_e_00 = m.e_11 * -1 * (1 / m.det());
    float temp_e_01 = m.e_10 * -1 * (1 / m.det());
    float temp_e_10 = m.e_01 * -1 * (1 / m.det());
    float temp_e_11 = m.e_00 * -1 * (1 / m.det());
    Mat2 temp{temp_e_00, temp_e_01, temp_e_10, temp_e_11};
    return temp;
}

Mat2 transpose(Mat2 const& m){
    float temp_e_00 = m.e_00;
    float temp_e_01 = m.e_10;
    float temp_e_10 = m.e_01;
    float temp_e_11 = m.e_11;
    Mat2 temp{temp_e_00, temp_e_01, temp_e_10, temp_e_11};
    return temp;
}

Mat2 make_rotation_mat2(float phi){
    float temp_e_00 = std::cos(phi);
    float temp_e_01 = (std::sin(phi) * -1);
    float temp_e_10 = std::sin(phi);
    float temp_e_11 = std::cos(phi);
    Mat2 temp{temp_e_00, temp_e_01, temp_e_10, temp_e_11};
    return temp;
}