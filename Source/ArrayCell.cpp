#include "ArrayCell.hpp"

// ArrayCell::defualtColor = sf::Color::Black;

void ArrayCell::setColor(sf::Color color){
    this->color = color;
}

void ArrayCell::setDefaultColor(){
    // this->color = defaultColor;
    this->color = sf::Color::Black;
}

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