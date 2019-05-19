#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include "circle.hpp"
#include <iostream>

using namespace std;



TEST_CASE("circle filter", "[copy_if]")
{
    Color red{ 1.0, 0.0, 0.0 };
    Color green{0.0, 1.0, 0.0};
    Color blue{ 0.0, 0.0, 1.0 };
    Color white{1.0, 1.0, 1.0};
    Vec2 circle_c{400.0f, 400.0f};
    vector<Circle> circles{ 
        Circle(circle_c, 5.0f, green, "second"),
        Circle(circle_c, 3.0f, blue, "minute"),
        Circle(circle_c, 1.0f, red, "hour"),
        Circle(Vec2(475.0f, 8.0f), 8.0f, white, "one"),
        Circle(Vec2(525.0f, 5.0f), 5.0f, white, "two"),
        Circle(Vec2(600.0f, 6.0f), 6.0f, white, "three"),
        Circle(circle_c, 4.0f, green, "secondC")
    };  

    vector<Circle> bigCircles(circles.size()); //This does not work without Circle::Circle(), so why not write default constructors?
   
    float cmp1 = 4.0f;
    auto greaterOrEqual = [cmp1] (const Circle& c) -> bool
    {
       return c.getRadius() >= cmp1;
    };

    auto it = std::copy_if(cbegin(circles), cend(circles), bigCircles.begin(), greaterOrEqual); //do the function
    bigCircles.resize(std::distance(bigCircles.begin(),it)); //resize it
    //got all that are cmp <= circle


    float cmp2 = 3.0f;
    auto greater = [cmp2] (const Circle& c) -> bool
    {
       return c.getRadius() > cmp2;
    };

    for(auto c : bigCircles){
        std::cout << c.getRadius() << std::endl;
    }

    REQUIRE(std::all_of(bigCircles.begin(), bigCircles.end(), greater));   


}
int main(int argc, char *argv[])
{
    return Catch ::Session().run(argc, argv);
}