#include <SFML/Graphics.hpp>
#include "Application.h"




const float test = 1.0 / 60.0f; 
int main()
{



    sf::RenderWindow window(sf::VideoMode(700,700), "Cloth Sim");
    window.setFramerateLimit(60);
    Application app(window);




    app.Setup(2,2,2);




    sf::Clock clock;
    sf::Time elapsedTime = sf::Time::Zero;
    const sf::Time timePerFrame = sf::seconds(1.0f / 60.0f); 
    float dt; 



    while (window.isOpen())
    {
    //sf::Time Elasped = clock.getElapsedTime();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

      sf::Time delta = clock.restart();
      elapsedTime += delta;

      while (elapsedTime >= timePerFrame)
    {
        app.Update(elapsedTime.asSeconds()); // Use the fixed timestep
        elapsedTime -= timePerFrame;
    }

       // app.Update(elapsedTime.asSeconds());
        window.clear();
        app.Render();
        window.display();
 
    }

    return 0;

}