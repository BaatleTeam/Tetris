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
    return (this->color == sf::Color::Black) ? false : true;
}

std::ostream& operator<<(std::ostream &out, const ArrayCell &cell){
    int number_Color = 0;

    if (cell.color == sf::Color::Black)
        number_Color = 0;
    if (cell.color == sf::Color::Red)
        number_Color = 1;
    if (cell.color == sf::Color::Green)
        number_Color = 2;
    if (cell.color == sf::Color::Blue)
        number_Color = 3;
    if (cell.color == sf::Color::Yellow)
        number_Color = 4;
    if (cell.color == sf::Color::Magenta)
        number_Color = 5;
    if (cell.color == sf::Color::Cyan)
        number_Color = 6;
    
    out << number_Color;
    return out;
}