#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>



struct Particle{

    sf::Vector2f pos;
    sf::Vector2f old_Pos;
    sf::Vector2f accel{0,0};
    float sim_time = 0.0f;
    float sim_frame_dt = 0.0f;
    float sim_subseps = 8;

   // Particle() = default;

    Particle(sf::Vector2f Position){
    pos = Position;
    }

  //  ~Particle() = default;


    void updatePosition(float dt){
        sf::Vector2f Vel = pos - old_Pos;
        old_Pos = pos;

        pos = pos + Vel + accel * dt * dt;

        accel = {};
    }


    void set_Update_Rate(float rate){

        sim_frame_dt = 1.0f / rate;
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

    void Gravity(sf::Vector2f grav){
        Accerlate(grav);
    }



    float get_step_dt() const {
        return sim_frame_dt / sim_subseps;
    }    



};
