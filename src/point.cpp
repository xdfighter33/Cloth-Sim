#include "point.h"





void Point::update_Point(float dt,float subSteps){
sf::Vector2f grav{0,200.0f};
float m_time;
float step_dt = dt / subSteps;

//step_dt += dt / 60;
uint32_t m_subStep = (uint32_t)60;

for(int i = 0; i < subSteps; i++ ) {
    ApplyGravity(grav);
    update_positions(step_dt);
}

}


void Point::set_step_dt(float rate){

}

void Point::update_Objects(float dt,float subSteps){


    //dt += 1.0f / 
    for(auto& obj : points){
        obj.set_Update_Rate(60);

    }
}




