#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>

using namespace std;

bool is_even(int n) { return n % 2 == 0; }



template <typename T, typename M> T filter(T const& v, M m) {
    T result (v.size()); //create return of same size
    auto it = std::copy_if(v.begin(), v.end(), result.begin(), m); //do the function
    result.resize(std::distance(result.begin(),it)); //resize it
    return result;
} 

TEST_CASE("make filter", "[filter,]")
{
    vector<int> v{1, 2, 3, 4, 5, 6};
    vector<int> all_even = filter(v, is_even);

    std::copy(std::cbegin(all_even), std::cend(all_even),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    REQUIRE(std::all_of(all_even.begin(), all_even.end(), is_even));
}

int main(int argc, char *argv[])
{
    return Catch ::Session().run(argc, argv);
}