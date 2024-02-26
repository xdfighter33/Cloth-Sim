#include <SFML/Graphics.hpp>
#include "Application.h"

int main()
{



    sf::RenderWindow window(sf::VideoMode(700,700), "Cloth Sim");
    Application app(window);
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


    
    sf::Clock clock;


    while (window.isOpen())
    {
      // sf::time Elasped = clock.restart();

        app.Setup(2,2,2);
  
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        window.clear();
        app.Update(clock);
        app.Render();
        window.display();
    }

    return 0;
}