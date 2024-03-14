#pragma once
#include <SFML/Graphics.hpp>
#include "point.h"

class Stick {
public:
  //  Stick() = default;
    Stick(Point& object1,Point& object2) {
        po1 = object1;
        po2 = object2;
        Pos1 = po1.get_pos();
    }
    ~Stick() = default;




    void set_positions(Point& object1, Point& object2,float length){
        Pos1 = po1.get_pos();
        Pos2 = object2.return_Object_position(object2);
        leng = length;
    std::cout << "Test: " <<Pos1.y << std::endl;
    }




    void set_shit(sf::Vector2f test1, sf::Vector2f test2){
        Pos1 = test1;
        Pos2 = test2;
    }

        sf::Vector2f getPos1() const {
        return Pos1;
    }


    void update();

    void GetLength();


    void test_positions() {
        std::cout << "Position test : " << Pos1.y << std::endl;
    }




        // Getter methods
     sf::Vector2f& getPos1()  { return Pos1; }
     sf::Vector2f& getPos2()  { return Pos2; }



    Particle& addObject1(Point& object){
    return stick.emplace_back(object.return_Object_position(object));
    }


    Particle& addObject2(Point& object){
    return stick.emplace_back(object.return_Object_position(object));
    }
    

const std::vector<Particle>& getObjects() const {
    return stick;
}


    
private:
    std::vector<Particle> stick;
    Point po1;
    Point po2;
    sf::Vector2f Pos1;
    sf::Vector2f Pos2;
    float leng;
};
