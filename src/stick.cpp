#include "stick.h"


void Stick::update(){

    float dx = Pos2.x - Pos1.x;
    float dy = Pos2.y - Pos1.y;

    float dist = sqrt(dx * dx + dy * dy);

    float diff = leng - dist;

    float percent = (diff / dist ) / 2;

    float offSet_x = dx * percent;
    float offSet_y = dy * percent;

    Pos1.x -= offSet_x;
    Pos1.y -= offSet_y;

    Pos2.x -= offSet_x;
    Pos2.y -= offSet_y;
    
    //std::cout <<"Testing out: " << Pos1.x << std::endl;

}


void Stick::GetLength(){

}