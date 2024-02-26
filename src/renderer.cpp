#include "renderer.h"

void Renderer::draw_line(int x0, int y0, int x1, int y1, uint32_t color) const{
        sf::Vertex line[] = {
              sf::Vertex(sf::Vector2f(10.f, 10.f)),
              sf::Vertex(sf::Vector2f(150.f, 150.f))
        };
        
        m_target.draw(line,2,sf::Lines);
      
}


void Renderer::draw_point(int x, int y, uint32_t color) const{
    sf::CircleShape circle(50.0f);
    circle.setPosition(sf::Vector2f(x,y));

    m_target.draw(circle);

}


void Renderer::draw_dot(const Point& points) const {
     sf::CircleShape circle{1.0f};
    circle.setPointCount(32);
    circle.setOrigin(1.0f,1.0f);

    
    const auto& obj = points.getObjects();

    for(const auto& objects : obj){
        circle.setPosition(objects.pos);
        circle.setRadius(10.0f);
        m_target.draw(circle);
        
    }


}
