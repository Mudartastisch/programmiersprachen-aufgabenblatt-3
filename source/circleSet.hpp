#ifndef CIRCLESET_HPP
#define CIRCLESET_HPP
#include "circle.hpp"
#include <set>
#include <string>
#include <iostream>
using namespace std; 

struct circleSet{
  circleSet(set<Circle*> s) : s(s) {}
  void operator()(Circle* add) const { 
      for (auto i: s) {
        if (!add->getName().compare(i->getName()))
        {
            std::cerr << "can't add circle of same name";
            exit(2);
        }
        
      }
  }

private:
  set<Circle*> s;
};



#endif //CIRCLESET_HPP