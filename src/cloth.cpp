#include "Cloth.h"
#include <iostream>

Cloth::Cloth(int width, int height, int spacing, int startX, int startY){
       points.push_back(&tests);
       points.push_back(&object1);
       points.push_back(&object2);
       points.push_back(&object3);
}

void Cloth::Update(float dt){
  //  tests.setVelo(sf::Vector2f(1.5,0.5));
    tests.update_Point(dt,8);
    object1.update_Point(dt,8);
    object2.update_Point(dt,8);
    object3.update_Point(dt,8);
    //tests.return_pos();
 //   std::cout <<  "Test " <<  << std::endl;
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
   renderer->draw_test_line(tests,object1);
  renderer->draw_test_line(object2,tests);
  renderer->draw_test_line(object2,object1);
  renderer->draw_test_line(object2,object3);
  renderer->draw_test_line(object3,object1);
  renderer->draw_test_line(tests,object3);
    }
   
}

