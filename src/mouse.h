#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Mouse{

private:
sf::Vector2f mouse_pos;
sf::Vector2f Prev_pos;

bool left_click_down = false; 
bool right_click_down = false; 

public: 

Mouse() = default;
~Mouse() = default;

void updatePosition(int x, int y);

const sf::Vector2f& GetPosition() const {return mouse_pos; }
const sf::Vector2f& GetPrevPosition() const {return Prev_pos; }

bool GetLeftButtonDown() const {return left_click_down;}
void SetLeftButtonDown(bool state){this->left_click_down = state;}
bool GetRighttButtonDown() const {return right_click_down;}
void SetRightButtonDown(bool state){this->right_click_down = state;}


};