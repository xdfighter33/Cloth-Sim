#include <SFML/Graphics.hpp>
#include "point.h"
class Stick {
public: 
    Stick() = default; 
    Stick(sf::Vector2f pos1, sf::Vector2f pos2);
    ~Stick();

    float Get_Distance(sf::Vector2f object, sf::Vector2f object1);
    sf::Vector2f Get_Difference(sf::Vector2f object1, sf::Vector2f object2);
    float GetLength(sf::Vector2f object);

private: 
std::vector<Particle> points;

};