#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>


class GameArray;

class ActiveShape {
private:
    std::vector <sf::Vector2u> coordinates;
    bool isActive_m;

public:
    ActiveShape(std::vector<sf::Vector2u> &&coord);
    ActiveShape();
    void moveDown();
    bool isActive() const;
    unsigned int getCellsNum() const;
    std::vector <sf::Vector2u> getCurCoordinates() const;
    void setInactive();
    void setActive();
};