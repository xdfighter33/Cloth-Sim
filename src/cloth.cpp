#include "Cloth.h"
#include <iostream>

Cloth::Cloth(int width, int height, int spacing, int startX, int startY){
       points.push_back(&tests);

}

void Cloth::Update(float dt){
  //  tests.setVelo(sf::Vector2f(1.5,0.5));
    tests.update_Point(dt,8);
    tests.return_pos();
}

void Cloth::Setup(sf::Vector2f Spawn_pos){
    
    tests.addObject(Spawn_pos);
  //  tests.setVelo(sf::Vector2f(0.5,0.5));
   // tests.addObject(sf::Vector2f(100,100));
    
}

void Cloth::Draw(Renderer* renderer) const {


 for (auto& particle : points) {

    renderer->draw_dot(tests);
        

    }

}

