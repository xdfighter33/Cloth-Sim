#pragma once
#include <SFML/Graphics.hpp>
#include "physics/Physics.hpp"


class Point{

public:
    Point() = default;
    Point(sf::Vector2f Position){
        Position = pos;
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


void set_step_dt(float rate);
const std::vector<Particle>& getObjects() const {
    return points;
}

void update_positions(float dt){

    for(auto& obj : points){
        obj.updatePosition(dt);
     //   obj.set_Velo(sf::Vector2f(50,50),dt);
    }
}

void set_size(float size);


Particle& addObject(){
    return points.emplace_back(pos);
}


void update_Objects(float dt,float subSteps);

void update_Point(float dt,float subSteps);


void ApplyGravity(sf::Vector2f grav){

    for(auto& obj : points){
        obj.Accerlate(grav);
    }
}



private:
std::vector<Particle> points;



float size = 150.0f;
sf::Vector2f pos;





    
};