#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "point.h"


class Renderer{
public:

bool set_up();
void draw_line(int x0, int y0, int x1, int y1, uint32_t color) const;
void draw_point(int x, int y, uint32_t color) const;
    explicit
    Renderer(sf::RenderTarget& target)
    :m_target{target}{}
 
sf::RenderTarget& getRenderTarget() {
        return m_target; // Assuming 'renderTarget' is the render target object in Renderer class
    }

void draw_test_line(const Point& object1, const Point&  object2);

void draw_dot(const Point& pointz) const; 


private:
int wind_width;
int wind_height;
sf::RenderTarget& m_target;
};