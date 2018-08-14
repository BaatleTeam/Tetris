#include "ActiveShape.hpp"

ActiveShape::ActiveShape(){
    isActive_m = false;
}

ActiveShape::ActiveShape(std::vector<sf::Vector2u> &&coord){
    coordinates = coord;
    isActive_m = true;
}

void ActiveShape::moveDown(){
    for (auto &elem : coordinates)
        elem.y--;
}

std::vector <sf::Vector2u> ActiveShape::getCurCoordinates() const {
    return coordinates;
}

bool ActiveShape::isActive() const {
    return isActive_m;
}

void ActiveShape::setInactive() {
    isActive_m = false;
}

void ActiveShape::setActive(){
    isActive_m = true;
}

unsigned int ActiveShape::getCellsNum() const {
    return coordinates.size();
}

Type0::Type0(unsigned int height, unsigned int width)
    : ActiveShape({
        { width/2,   height-1 },
        { width/2+1, height-1 },
        { width/2,   height-2 },
        { width/2+1, height-2 }
     }) 
{ 

}

void Type0::rotate(const GameArray& array) {
    // nothihg
}

Type1::Type1(unsigned int height, unsigned int width)
    : ActiveShape({
        { width/2,   height-1 },
        { width/2+1, height-1 },
        { width/2,   height-2 },
        { width/2+1, height-2 }
     }) 
{ 

}

void Type1::rotate(const GameArray& array) {
    // nothihg
}
