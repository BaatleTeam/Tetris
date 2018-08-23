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
    return _isPainted;
}

void ArrayCell::makePainted(){
    this->_isPainted = true;
}

void ArrayCell::makeUnpainted(){
    this->_isPainted = false;
}