#include <vector>
#include "renderer.h"
#include "mouse.h"
#include "point.h"


class Cloth{

Point tests;
private:

    sf::Vector2f gravity = {0,10.0f};
    float drag = 0.01;
    float elasticity = 10.0f;

    std::vector<Point*> points;
    //std::vector<Stick*> sticks;
public:

Cloth() = default;
Cloth(int width, int height, int spacing, int StartX, int StartY);
~Cloth();
void test();
void Setup(sf::Vector2f Spawn_pos);
//void Update(Renderer* renderer, Mouse* mouse, float deltaTime);
void Update(float dt);
void Draw(Renderer* renderer) const;
};