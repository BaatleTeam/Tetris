#pragma once
#include <SFML/Graphics/Color.hpp>

// Ячейка игрового массива

class ArrayCell {
private:
    bool _isPainted;
    sf::Color color;

public:
    ArrayCell() = default;

    void setColor(sf::Color color);
    sf::Color getColor() const;

    bool isPainted() const;
    void makePainted();
    void makeUnpainted();
};