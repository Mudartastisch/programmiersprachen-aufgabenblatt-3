#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"  
#include "mat2.hpp"
#include "circle.hpp"
#include <algorithm>

using namespace std; 

//https://www.walletfox.com/course/sortvectorofcustomobjects11.php

TEST_CASE("sorted") {
    Color red{ 1.0, 0.0, 0.0 };
    Color green{0.0, 1.0, 0.0};
    Color blue{ 0.0, 0.0, 1.0 };
    Color white{1.0, 1.0, 1.0};
    Vec2 circle_c{400.0f, 400.0f};
    vector<Circle> sorted_circles{ 
        Circle(circle_c, 200.0f, green, "second"),
        Circle(circle_c, 100.0f, blue, "minute"),
        Circle(circle_c, 50.0f, red, "hour"),
        Circle(Vec2(475.0f, 275.0f), 25.0f, white, "one"),
        Circle(Vec2(525.0f, 325.0f), 75.0f, white, "two"),
        Circle(Vec2(600.0f, 400.0f), 150.0f, white, "three"),
        Circle(circle_c, 200.0f, green, "secondC")
    };

    struct A_8_functor {
        A_8_functor() {}
        bool operator()(const Circle& c1, const Circle& c2) const {
            return c1.getRadius() < c2.getRadius();
        }
    };

    sort(sorted_circles.begin(), sorted_circles.end(), A_8_functor());
    for(auto i: sorted_circles){
        i.debug();
    }
    REQUIRE(is_sorted(sorted_circles.begin(), sorted_circles.end()));
}


int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}