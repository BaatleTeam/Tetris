#pragma once
#include <SFML/Graphics/Color.hpp>

// Ячейка игрового массива

class ArrayCell {
private:
    bool _isPainted;
    sf::Color color;
    // static const sf::Color defaultColor;

public:
    ArrayCell() = default;

    void setColor(sf::Color color);
    void setDefaultColor();
    sf::Color getColor() const;

    bool isPainted() const;
    void makePainted();
    void makeUnpainted();

    ArrayCell& operator=(const ArrayCell& arrayCell){
        if (this == &arrayCell)
            return *this;
        _isPainted = arrayCell._isPainted;
        color = arrayCell.color;
        return *this;
    }
};