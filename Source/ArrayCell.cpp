#include "ArrayCell.hpp"

inline
void ArrayCell::setColor(sf::Color color){
    this->color = color;
}

inline
sf::Color ArrayCell::getColor() const {
    return color;
}

bool ArrayCell::isPainted() const {
    return isActive;
}

void ArrayCell::makePainted(){
    this->isActive = true;
}

void ArrayCell::makeUnpainted(){
    this->isActive = false;
}