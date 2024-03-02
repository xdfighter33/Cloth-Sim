#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>



struct Particle{

    sf::Vector2f pos;
    sf::Vector2f old_Pos;
    sf::Vector2f accel;

   // Particle() = default;

    Particle(sf::Vector2f Position)
        : pos{Position}
        , old_Pos{Position}
        , accel{0.0f,0.0f}
        {}
    

  //  ~Particle() = default;


    void updatePosition(float dt){
        sf::Vector2f Vel = pos - old_Pos;

        old_Pos = pos;

        pos = pos + Vel + accel * (dt * dt); 

        accel = {};
    }

    void Accerlate(sf::Vector2f force){
        accel += force;
    }
    
    void set_Velo(sf::Vector2f v, float dt){
        old_Pos = pos - (v * dt);

    }

    void AddVelocity(sf::Vector2f v, float dt){
        old_Pos -= v * dt;
    }   





    sf::Vector2f getVelocity(float dt) const
    {
        return (pos - old_Pos) / dt;
    }


   const sf::Vector2f Get_Pos() const {
        
        return pos; 
    }

};


