#pragma once
#include <iostream>
#include <iomanip>
#include "ArrayCell.hpp"
#include "Settings.hpp"
#include "ShapeGenerator.hpp"
#include "ActiveShape.hpp"

class ActiveShape;
class ShapeGenerator;

class GameArray {
private:
    unsigned int width; 
    unsigned int height;
    std::vector <std::vector <ArrayCell> > ptrArray;

    std::unique_ptr<ActiveShape> activeShape;
    ShapeGenerator shapeGenerator;
    
public:
    GameArray(const Settings&);
    ~GameArray();
    void doStep(); // перемещает активную фигуру на этаж ниже или генерит новую
    bool checkShapeMoving() const;
    bool isPainted(sf::Vector2u coord) const;
    void displayActiveShapeOnArray();
    void removeActiveShapeFromArray();
    
    friend std::ostream& operator<<(std::ostream &out, const GameArray &gmr);
};