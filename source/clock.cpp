#include "window.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include "vec2.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "color.hpp"
#include <iostream>
#include <set>
#include <string>
#include "circleSet.hpp"

using namespace std; 



int main(int argc, char* argv[])
{
  Window win{std::make_pair(800,800)};
  Color red{ 1.0, 0.0, 0.0 };
  Color green{0.0, 1.0, 0.0};
  Color blue{ 0.0, 0.0, 1.0 };
  Color white{1.0, 1.0, 1.0};
  Vec2 circle_c{400.0f, 400.0f};
 

  set<Circle*> active_objects; //can't do the naming thing, did something wrong with circleSet


  Circle second(circle_c, 200.0f, green, "second");
  Circle minute(circle_c, 100.0f, blue, "minute");
  Circle hour(circle_c, 50.0f, red, "hour");

  Circle one(Vec2(475.0f, 275.0f), 25.0f, white, "one");
  Circle two(Vec2(525.0f, 325.0f), 75.0f, white, "two");
  Circle three(Vec2(600.0f, 400.0f), 150.0f, white, "three");
  
  active_objects.insert(&one);
  active_objects.insert(&two);
  active_objects.insert(&three);

  
  string circleName;
  bool running;
  bool timeReset = true;
  double startTime;
  while (!win.should_close()) {
    if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
      win.close();
    }
    
    auto t = win.get_time();
    if(timeReset){
      startTime = t;
      timeReset = false;
      running = true;
      std::cout<< "Did startTime" << "\n";
    }
    
	  double currentTime = t - startTime;
    std::cout<< currentTime << "\n";
		
    //task stuff

    second.drawClock(win,t*360);
    minute.drawClock(win,t*60);
    hour.drawClock(win,t);


    if( currentTime >= 10.0 ) //10 seconds.
		{      
      while(running){

        std::cout<< "What circle?" << "\n";
        std::cin >> circleName;

        for (auto i: active_objects) {          
          if(!circleName.compare(i->getName())){ //this is not what I expected, an Integer?! sure, but the name is confusing
            i->setColor(red);            
            running = false;
            i->debug();
          }
          else
          {
            i->setColor(white);
          }                    
        }

        if(running){
          std::cout<< "That circle does not exist" << "\n";
          std::cout<< "Select from:" << "\n";
          for (auto i: active_objects) {
            std::cout<< i->getName() << "\n";
          }        
        }
      }			
			timeReset = true; //Reset the timer.
		}

    for (auto i: active_objects) {
      i->draw(win);
    }

    win.update();
  }

  return 0;
}
