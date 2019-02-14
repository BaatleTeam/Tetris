#pragma once
#include <SFML/Graphics/Color.hpp>
#include <iostream>

// Ячейка игрового массива

class ArrayCell {
private:
    bool _isPainted;
    sf::Color color;
    // static const sf::Color defaultColor;
    // defultColor ~ Color Of BackGround

public:
    ArrayCell() = default;

    void setColor(sf::Color color);
    void setDefaultColor();
    sf::Color getColor() const;
    bool isPainted() const;

    friend std::ostream& operator<<(std::ostream &out, const ArrayCell &cell);
};