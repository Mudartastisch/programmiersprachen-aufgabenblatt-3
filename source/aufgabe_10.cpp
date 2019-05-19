#include <list>
#include <set>
#include <iterator>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    //3.2
    list<unsigned int> listOfNumbers; //create list
    set<int> comparison;              //create set
    srand(time(NULL));                //random seed
    for (int i = 0; i < 100; i++)
    {
        listOfNumbers.push_back(rand() % 100); //fill set with rand 0-99
        comparison.insert(i);                  //use the iterator to fill the list
    }

    list<unsigned int>::iterator itr;
    for (itr = listOfNumbers.begin(); itr != listOfNumbers.end(); ++itr)
    {
        comparison.erase(*itr); //delete the numbers that exist in listOfNumbers
    }

    //task does not properly define requested list
    vector<int> v_0; //From first List
    std::cout << "Random int list \n";
    copy(cbegin(listOfNumbers), cend(listOfNumbers), back_inserter(v_0));
    std::copy(std::cbegin(v_0), std::cend(v_0),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";
    std::cout << endl;


    vector<int> v_1; //From erased set
    std::cout << "Not found int \n";
    copy(cbegin(comparison), cend(comparison), back_inserter(v_1));
    std::copy(std::cbegin(v_1), std::cend(v_1),
              std::ostream_iterator<int>(std::cout, " "));
    std::cout << "\n";

    return 0;
}