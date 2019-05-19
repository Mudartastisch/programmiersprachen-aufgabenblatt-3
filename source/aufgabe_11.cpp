#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

using namespace std;
bool is_multiple_of_3(int i)
{
    return i % 3 == 0;
}

TEST_CASE("filter alle vielfache von drei", "[erase]")
{
    vector<unsigned int> v_0;
    srand (time(NULL)); //random seed
    for (int i = 0; i < 100; i++)
    {
        v_0.push_back(rand() % 100); //fill set with rand 0-99
    }

    //https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
    //invert result of is_multiple_of_3 with std::not1
    //this requires is_multiple_of_3 to be encapsulated in ptr_fun
    std::copy(std::cbegin(v_0), std::cend(v_0),
              std::ostream_iterator<int>(std::cout, " "));
    v_0.erase(std::remove_if(v_0.begin(), v_0.end(), std::not1(std::ptr_fun(is_multiple_of_3))), v_0.end());    

    std::cout << "\n" << "Only mod 3 remaining" << std::endl;
    std::copy(std::cbegin(v_0), std::cend(v_0),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::cout << endl;
    REQUIRE(std::all_of(v_0.begin(), v_0.end(), is_multiple_of_3));
}

int main(int argc, char *argv[])
{
    return Catch ::Session().run(argc, argv);
}