#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include "vec2.hpp"  
#include "mat2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"

  Vec2 vec_zero_zero{};
	Vec2 vec_zero_one{ 0.0,1.0 };
	Vec2 vec_one_zero{ 1.0,0.0 };
	Vec2 vec_one_one{ 1.0,1.0 };
	Vec2 vec_nThree_five{ -3.0,5.0 };
	Vec2 vec_nFour_nFour{ -4.0,-4.0 };
	Vec2 vec_five_two{ 5.0,2.0 };
	Vec2 vec_seven_one{ 7.0,1.0 };
  
TEST_CASE("test_vec2_hpp") {
  Vec2 a = Vec2() ; // requires that 0.0f == a.x and 0.0f == a.y
  REQUIRE(0.0f == a.x);
  REQUIRE(0.0f == a.y);
  Vec2 b {5.1f, -9.3f }; /* requires that 5.1 f == Approx ( b . x ) and -9.3 f == Approx ( b . y ) */
  REQUIRE(5.1f == Approx(b.x));
  REQUIRE(-9.3f == Approx(b.y));

}

TEST_CASE("test_vec2_cpp_plus"){

  //operator+
	Vec2 vec_prove_add_two_two{ operator+(vec_one_one, vec_one_one) };
	REQUIRE(vec_prove_add_two_two.x == 2.0f); //1+1=2
	REQUIRE(vec_prove_add_two_two.y == 2.0f); //1+1=2

	Vec2 vec_prove_add_nSeven_one{ operator+(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_add_nSeven_one.x == -7.0f); //-4+-3=-7
	REQUIRE(vec_prove_add_nSeven_one.y == 1.0f); //-4+5=1

	Vec2 vec_prove_add_seven_one{ operator+(vec_seven_one,vec_zero_zero) };
	REQUIRE(vec_prove_add_seven_one.x == 7.0f); //7+0=7
	REQUIRE(vec_prove_add_seven_one.y == 1.0f); //1+0=1
}

TEST_CASE("test_vec2_cpp_minus"){
  //operation-
	Vec2 vec_prove_sub_zero_zero{ operator-(vec_one_one,vec_one_one) };
	REQUIRE(vec_prove_sub_zero_zero.x == 0.0f); //1-1=0
	REQUIRE(vec_prove_sub_zero_zero.y == 0.0f); //1-1=0

	Vec2 vec_prove_sub_two_nOne{ operator-(vec_seven_one,vec_five_two) };
	REQUIRE(vec_prove_sub_two_nOne.x == 2.0f); //7-5=2
	REQUIRE(vec_prove_sub_two_nOne.y == -1.0f); //1-2=-1

	Vec2 vec_prove_sub_nOne_nNine{ operator-(vec_nFour_nFour,vec_nThree_five) };
	REQUIRE(vec_prove_sub_nOne_nNine.x == -1.0f); //-4--3=-1
  REQUIRE(vec_prove_sub_nOne_nNine.y == -9.0f); //-4-5=-9
}

TEST_CASE("test_vec2_cpp_multiply"){
  //operator*
  //Vec2, float
	Vec2 vec_prove_mul_two_two{ operator*(vec_one_one,2.0) };
	REQUIRE(vec_prove_mul_two_two.x == 2.0f); //1*2=2
	REQUIRE(vec_prove_mul_two_two.y == 2.0f); //1*2=2

	Vec2 vec_prove_mul_one_zeroFour{ operator*(vec_five_two,0.2f) };
	REQUIRE(vec_prove_mul_one_zeroFour.x == 1.0f); //5*0.2=1
	REQUIRE(vec_prove_mul_one_zeroFour.y == 0.4f); //2*0.2=0.4

  //float, Vec2
	Vec2 vec_prove_mul_twoFourFive_zeroThreeFive{ operator*(0.35f,vec_seven_one) };
	REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.x == 2.45f); //7*0.35=2.45
  REQUIRE(vec_prove_mul_twoFourFive_zeroThreeFive.y == 0.35f); //1*0.35
}

TEST_CASE("test_vec2_cpp_devide"){
  //operator/
	Vec2 vec_prove_div_threeFive_zeroFive{ operator/(vec_seven_one,2.0f) };
	REQUIRE(vec_prove_div_threeFive_zeroFive.x == 3.5f); //7/2=3.5
	REQUIRE(vec_prove_div_threeFive_zeroFive.y == 0.5f); //1/2=0.5

	Vec2 vec_prove_div_ten_four{ operator/(vec_five_two, 0.5f) };
	REQUIRE(vec_prove_div_ten_four.x == 10.0f); //5/0.5=10
	REQUIRE(vec_prove_div_ten_four.y == 4.0f); //2/0.5=4

	Vec2 vec_prove_div_nOneFive_woFive{ operator/(vec_nThree_five,2.0f) };
	REQUIRE(vec_prove_div_nOneFive_woFive.x == -1.5f); //5/0.5=10
  REQUIRE(vec_prove_div_nOneFive_woFive.y == 2.5f); //2/0.5=4
}

TEST_CASE("test_mat2_mult"){
	Mat2 Mat_30_50_25_40{ 30,50,25,40 };
	Mat2 Mat_2_3_1_1{ 2,3,1,1 };
	Mat2 Mat_110_140_90_115{ operator*(Mat_30_50_25_40,Mat_2_3_1_1) };
	REQUIRE(Mat_110_140_90_115.e_00 == 110.0f);
	REQUIRE(Mat_110_140_90_115.e_01 == 140.0f);
	REQUIRE(Mat_110_140_90_115.e_10 == 90.0f);
	REQUIRE(Mat_110_140_90_115.e_11 == 115.0f);
}

float circumference(Circle& c){
	//2*pi*r
	return 2 * M_PI * c.getRadius();
}

float circumference(Rectangle& r){
	//2*(xdifference + ydifference)
	return 2 * ((r.getMax().x - r.getMin().x) + (r.getMax().y - r.getMin().y));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
