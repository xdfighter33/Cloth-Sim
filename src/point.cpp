#include "point.h"





void Point::update_Point(float dt,float subSteps){

 uint32_t numSubsteps = calculateNumSubsteps(dt);    
shit.setSubsStepscount(10);
shit.setSimulationUpdateRate(60);
shit.update();

float step_dt = shit.getStepDt();




// Declare Variables; 
//debug_variables(step_dt);



sf::Vector2f grav{0,200.0f};


uint32_t tittys = shit.return_sub_steps();


//Debug Test 


//set_velocity(sf::Vector2f(50,0),step_dt);

for(uint32_t i(shit.return_sub_steps()); i--;) {
    ApplyGravity(grav);
  // setVelo(sf::Vector2f(2,0));
  // setAccel(sf::Vector2f(5,800.0f ));
   appplyConstraint(step_dt);
    update_positions(step_dt);
}

}

void Point::setAccel(sf::Vector2f force){
    for(auto& obj: points){

        shit.addAccerlation(obj,force);
    }

}
void Point::set_step_dt(float rate){

}

void Point::setVelo(sf::Vector2f velo){

    for(auto& obj: points){

        
    // 

    }

}

void Point::debug_variables(float dt){

//std::cout << "M Frame: "  <<shit.return_m_frame() << std::endl;
//std::cout << "M time: " << shit.return_time() << std::endl; 
//std::cout << "Step DT: " << shit.getStepDt() << std::endl;
//std::cout << "Sub Step: " << shit.return_sub_steps() << std::endl;
//Velo(dt);
//get_pos();


}

void Point::Velo(float dt ){
    sf::Vector2f VELO;
    for(auto& obj : points){
      VELO.x =  obj.getVelocity(dt).x;
      VELO.y =  obj.getVelocity(dt).y;
    }



std::cout << "Velocity: x " << VELO.x << "\n" << "Veloicty y: "<< VELO.y  << std::endl;

}
uint32_t Point::calculateNumSubsteps(float dt) {
    // Adjust the number of substeps based on elapsed time
    // You can define your own criteria for adjusting substeps
    if (dt < 0.016f) { // Example threshold (corresponds to ~60 FPS)
        return 1; // Default substeps
    } else {
        return static_cast<uint32_t>(dt / 0.016f); // Adjust substeps based on elapsed time
    }
}




