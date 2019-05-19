#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

using namespace std;

auto add = [] (const int& a, const int& b) -> int
    {
       return a + b;
    };

bool equalTen(int i) { return i == 10;}

TEST_CASE("combine vectors", "[transform]")
{
    vector<int> v_1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> v_2{9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v_3(9);
    transform(cbegin(v_1), cend(v_1), cbegin(v_2), v_3.begin(), add);

    std::copy(std::cbegin(v_3), std::cend(v_3),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::cout << endl;

    REQUIRE(std::all_of(v_3.begin(), v_3.end(), equalTen));

}

int main(int argc, char *argv[])
{
    return Catch ::Session().run(argc, argv);
}