#include "Cloth.h"
#include <iostream>



Cloth::Cloth(int width, int height, int spacing, int startX, int startY){


       points.push_back(&tests);
       points.push_back(&object1);
       points.push_back(&object2);
       points.push_back(&object3);
       sticks.push_back(new Stick(tests,object1));


        firstStick = sticks[0];
        
    //   std::cout << stick.return_pos1().x << std::endl;
}

void Cloth::Update(float dt){


  
    
  // Stick objects 
 // std::cout << "Position of this object is: " << tests.return_test_position(object1).y;

  //Point objects 


   // std::cout << "First Stick " <<  << std::endl;

    tests.update_Point(dt,8);
    object1.update_Point(dt,8);
    object2.update_Point(dt,8);
    object3.update_Point(dt,8);

  
    std::cout << "Print first Version: " << firstStick->getPos1().x << std::endl;

   
    //  stick.set_positions(object1,object2);
    //tests.return_pos1(object1);
    //tests.test_return(object1);
   
  
}

void Cloth::Setup(sf::Vector2f Spawn_pos){

    


    
    tests.addObject(Spawn_pos);

   // tests.addObject(Spawn_pos.x + 200, Spawn_pos.y + 200);


    object1.addObject(sf::Vector2f(150,200));
    object2.addObject(sf::Vector2f(100,250));
    object3.addObject(sf::Vector2f(150,250));




}

void Cloth::Draw(Renderer* renderer) const {


 for (auto& particle : points) {
    
    renderer->draw_dot(tests);
    renderer->draw_dot(object1);
    renderer->draw_dot(object2);     
    renderer->draw_dot(object3);
   // renderer->draw_line(object1.get_pos().x,object1.get_pos().y,object2.get_pos().x,object2.get_pos().y,0);
   renderer->draw_test_line1(tests,object1);
  //renderer->draw_test_line(object2,tests);
  //renderer->draw_test_line(object2,object1);
  //renderer->draw_test_line(object2,object3);
  //renderer->draw_test_line(object3,object1);
  //renderer->draw_test_line(tests,object3);
  //renderer->draw_test_line1(stick);
    }
   
  for (auto& lines : sticks) {

 //   renderer->draw_test_line1(stick);
  }
}

