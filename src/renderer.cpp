#include "renderer.h"

void Renderer::draw_line(int x0, int y0, int x1, int y1, uint32_t color) const{

        sf::CircleShape circle(50.0f);
        circle.setPosition(x0,y0);
        sf::Vertex line[] = {
              sf::Vertex(sf::Vector2f(x0, y0)),
              sf::Vertex(sf::Vector2f(x1, y1))
        };
        
        m_target.draw(line,2,sf::Lines);
      
}


void Renderer::draw_point(int x, int y, uint32_t color) const{
    sf::CircleShape circle(50.0f);
    circle.setPosition(sf::Vector2f(x,y));

    m_target.draw(circle);

}
void Renderer::draw_test_line1(const Stick& stick) {


}






void Renderer::draw_circle_line(const Point& object 1, const Point& object2){
    
}
void Renderer::draw_test_line(const Point& object1, const Point& object2) {
    const auto& obj1 = object1.getObjects();
    const auto& obj2 = object2.getObjects();
    
    for (const auto& ob1 : obj1) {
        for (const auto& ob2 : obj2) {
            sf::CircleShape circle;
            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(ob1.pos)),
                sf::Vertex(sf::Vector2f(ob2.pos))
            };

            m_target.draw(line, 2, sf::Lines);
        }
    }
}

void Renderer::draw_dot(const Point& points) const {
     sf::CircleShape circle{1.0f};
    circle.setPointCount(12);
    circle.setOrigin(1.0f,1.0f);

    
    const auto& obj = points.getObjects();


    for(const auto& objects : obj){
        circle.setPosition(objects.pos);
        circle.setRadius(10.0f);
        m_target.draw(circle);
        
    }


}
