#include <SFML/Graphics.hpp>
#include <iostream>
#include "mouse.h"
#include "Cloth.h"
#include "renderer.h"
#include "physics/Physics.hpp"

struct Application{

private: 

Renderer* renders = nullptr;

Cloth* cloth = nullptr;


bool is_running = false;

uint32_t LastDeltaTime;


public:

    sf::Time clock;
    Application() = default;

    Application(sf::RenderTarget& target){
        renders = new Renderer(target);
    }

    ~Application() = default;


    
   // bool is_running() const;

   void Setup(int ClothWidth, int ClothHeight, int ClothSpacing);
  //   void setUp(sf::RenderWindow test);
    void Input();

    void Update(sf::Clock Clock);

    void Render();

    void destroy();

};