#include "Cloth.h"
#include <iostream>

Cloth::Cloth(int width, int height, int spacing, int startX, int startY){

    for (int y = 0; y <= height; y++) {
		for (int x = 0; x <= width; x++){

           Point* point = new Point(sf::Vector2f(100,200));

            if(x != 0){
                points.push_back(&tests);

            }


        }

    }

}

void Cloth::Update(float dt){
    tests.set_velocity(sf::Vector2f(25.5,0.5),dt);
    tests.update_Point(dt,6);
    //tests.set_velocity(sf::Vector2f(5,5),dt);
    tests.update_Objects(8,60);
}

void Cloth::Setup(sf::Vector2f Spawn_pos){
    
    tests.addObject(Spawn_pos);

}

void Cloth::Draw(Renderer* renderer) const {


 for (auto& particle : points) {

    renderer->draw_dot(tests);
        

    }

}

