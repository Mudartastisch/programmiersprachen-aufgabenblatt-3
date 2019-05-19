
#include <cstdlib>   //std::rand()
#include <vector>    //std::vector<>
#include <list>      //std::list<>
#include <iostream>  //std::cout
#include <iterator>  //std::ostream_iterator<>
#include <algorithm> //std::reverse, std::generate

int main()
{
    std::vector<int> v_0(10); //create a vector of integers of size 10
    for (auto &v : v_0){
        v = std::rand(); //fill with random integers
    }

    std::copy(std::cbegin(v_0), std::cend(v_0), //copy iterativly from v_0
     std::ostream_iterator<int>(std::cout, "\n")); //with the use of ostream into cout (break line each time as delimiter)

    std::list<int> l_0(std::cbegin(v_0), std::cend(v_0)); //copy v_0 into l_0
    std::list<int> l_1(std::cbegin(l_0), std::cend(l_0)); //copy l_0 into l_1
    std::reverse(std::begin(l_1), std::end(l_1)); //reverse the order of l_1
    std::copy(std::cbegin(l_1), std::cend(l_1), //copy iterativly from l_1
    std ::ostream_iterator<int>(std::cout, "\n"));//with the use of ostream into cout (break line each time as delimiter)

    l_1.sort(); //sort l_1
    std::copy(l_1.cbegin(), l_1.cend(), //copy iterativly from l_1
    std::ostream_iterator<int>(std::cout, "\n")); //with the use of ostream into cout (break line each time as delimiter)

    //http://www.cplusplus.com/reference/algorithm/generate/
    std::generate(std::begin(v_0), std::end(v_0), std::rand); //fill v_0 with random intergers, same result as first, but in while loop
    std::copy(v_0.crbegin(), v_0.crend(),  //copy iterativly from v_0
    std::ostream_iterator<int>(std::cout, "\n"));//with the use of ostream into cout (break line each time as delimiter)

    return 0;
}