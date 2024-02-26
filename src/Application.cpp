#include "Application.h"


void Application::Update(sf::Clock Clock){
    sf::Clock clock;
    float current_time = Clock.getElapsedTime().asSeconds();

    float DeltaTime = (current_time - LastDeltaTime) / 1000.f;
 //   LastDeltaTime = current_time;


    std::cout << current_time << std::endl;
    cloth->Update(current_time);
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
