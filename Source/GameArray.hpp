#pragma once
#include <iostream>
#include <iomanip>
#include "ArrayCell.hpp"
#include "Settings.hpp"

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
    // bool canDoNextStep(const GameArray &field) const;
};

class GameArray {
private:
    unsigned int width;
    unsigned int height;
    ArrayCell **ptrArray;
    ActiveShape activeShape;
    

public:
    GameArray(const Settings&);
    ~GameArray();
    void doStep(); // перемещает активную фигуру на этаж ниже
    bool checkShapeMoving() const;
    bool isPainted(sf::Vector2u coord) const;
    void displayActiveShapeOnArray();
    void removeActiveShapeFromArray();
    
    friend std::ostream& operator<<(std::ostream &out, const GameArray &gmr);

private:
    void freeArray();
};