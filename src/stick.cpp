#include "stick.h"

float Stick::Get_Distance(sf::Vector2f object1,sf::Vector2f object){
    

    float distance_x = object1.x - object1.x;
    float distance_y = object1.y - object1.y;

    distance_x *= distance_x;
    distance_y *= distance_y;
    return distance_x + distance_y;
}


float Stick::GetLength(sf::Vector2f object){
    


    float distance_x = object.x;
    float distance_y = object.y;

    distance_x *= distance_x;
    distance_y *= distance_y;
    return distance_x + distance_y;
}

sf::Vector2f Stick::Get_Difference(sf::Vector2f object1, sf::Vector2f object2){

    sf::Vector2f Temp; 
    float disrtance_x = object1.x - object2.x;
    float disrtance_y = object1.y - object2.y;



    return sf::Vector2f(disrtance_x,disrtance_y);
}

