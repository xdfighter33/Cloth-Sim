#pragma once
#include <SFML/Graphics.hpp>
#include "physics/Physics.hpp"
#include "physics/Sim.hpp"


class Point{

public:
    Point() = default;
    Point(sf::Vector2f Position){
        Position = pos;
        shit.setSimulationUpdateRate(60);
    }
    ~Point() = default;


    Particle& addObject(sf::Vector2f position)
    {
        return points.emplace_back(position);
    }




void set_velocity(sf::Vector2f v,float dt){
    for(auto& obj : points){
        obj.set_Velo(v,dt);
    }
};




//REAL RETURN POSITIONS FUNCTION
sf::Vector2f return_Object_position(const Point& obj){
    sf::Vector2f temp;
    const auto& obj1 = obj.getObjects();
    for(const auto& object : obj1){
       temp.x = object.Get_Pos().x;
       temp.y = object.Get_Pos().y;
    }
    return temp; 
}



void set_step_dt(float rate);

const std::vector<Particle>& getObjects() const {
    return points;
}
void debug_variables(float dt);



void Velo(float dt);

uint32_t calculateNumSubsteps(float dt);


void update_positions(float dt){

    for(auto& obj : points){
        shit.updateObject(obj,dt);
    }
}

void set_size(float size);


Particle& addObject(){
    return points.emplace_back(pos);
}



void update_positions(float dt,float subSteps);

void update_Point(float dt,float subSteps);


void ApplyGravity(sf::Vector2f grav){

    for(auto& obj : points){
        obj.Accerlate(grav);
    }
}


void setVelo(sf::Vector2f);


void setAccel(sf::Vector2f force);





sf::Vector2f get_pos() const{
    return pos;
}


void appplyConstraint(float dt)
{
    for (auto& obj : points){
        const uint64_t object_count = points.size();

        for (uint64_t i{0}; i < object_count; i++)
        {
            Particle& object = points[i];
            if(object.Get_Pos().y >= 750)
            {
                object.pos.y += -1;
            }
            if(object.Get_Pos().y <= 0)
            {
                object.pos.y += 1;
            }
             if(object.Get_Pos().x >= 750)
            {
                object.pos.x += -1;
            }
             if(object.Get_Pos().x <= 25)
            {
                object.pos.x += 1;
            }
        }
    }
}



    


private:

std::vector<Particle> points;
//std::vector<Stick> sticks;

Simulator shit;


float size = 150.0f;
sf::Vector2f pos;





    
};


