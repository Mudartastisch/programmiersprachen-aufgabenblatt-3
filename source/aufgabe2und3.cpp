#include <list> 
#include <set>
#include <iterator> 
#include <iostream>
#include <map>
using namespace std; 

int main() 
{ 	
    //3.2
    std::list<unsigned int> listOfNumbers; //create list
    std::set<int> comparison; //create set
    srand (time(NULL)); //random seed
    for (int i = 0; i < 100; i++)
    {
        listOfNumbers.push_back(rand() % 100); //fill set with rand 0-99
        comparison.insert(i); //use the iterator to fill the list
    }

    list <unsigned int>::iterator itr;
    for (itr = listOfNumbers.begin(); itr != listOfNumbers.end(); ++itr) 
    { 
        comparison.erase(*itr); //delete the numbers that exist in listOfNumbers
    } 

    std::cout << "not in list: " << '\n';
    for (int n : comparison) {
        std::cout << n << '\n';
    }
    std::cout << "\n";

    //3.3
    std::map<int,int> occurrence;
    for (itr = listOfNumbers.begin(); itr != listOfNumbers.end(); ++itr) 
    { 
        occurrence[*itr]++;
    } 

    map<int, int>::iterator itr2;
    for (itr2 = occurrence.begin(); itr2 != occurrence.end(); ++itr2) { 
        cout << itr2->first << " : " << itr2->second << '\n'; 
    } 
    cout << endl; 




    return 0;
}
