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
