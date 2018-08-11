#pragma once
#include <SFML/Graphics/Color.hpp>

class ArrayCell {
private:
    bool isActive;
    sf::Color color;

public:
    ArrayCell() = default;

    void setColor(sf::Color color);
    sf::Color getColor() const;

    bool isPainted() const;
    void makePainted();
    void makeUnpainted();
};