#include "Application.h"


void Application::Update(float Clock){
//    sf::Clock clock;
//    int current_time = clock.getElapsedTime().asSeconds();

//    float DeltaTime = (current_time - LastDeltaTime) / 1000.0f;
  //  LastDeltaTime = current_time;

   // Clock.restart();

    std::cout << "Clock: " << Clock << std::endl;
    
    cloth->Update(Clock);

}

void Application::Setup(int ClothWidth, int ClothHeight, int ClothSpacing){

    cloth = new Cloth(200,200,5,200,200);
    
    cloth->Setup(sf::Vector2f(100,200));
}

//void Application::Update(){
//    cloth->Update(clock);
//}
void Application::Render()  {


        cloth->Draw(renders);

}
