#pragma once
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "GameField.hpp"
#include "../FigureTypeEnum.hpp"

class GameField;

// Базовый класс для различных типов фигур
// Хранит координаты каждой клеточки фигуры и кол-во вариантов поворота
using matrix = std::vector<std::vector <int>>;

class TetrisFigure {
private:
    unsigned curX;
    unsigned curY;
    matrix figureMatrix;
    sf::Color color;
    mutable std::vector <sf::Vector2u> coordinates;

public:
    TetrisFigure(FigureType type, int fieldHeight, int fieldWidth);
    TetrisFigure() = delete;
    virtual ~TetrisFigure() = default;

    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();
    
    std::vector <sf::Vector2u> getCurCoordinates() const;
    const matrix& getFigureMatrix() const;
    unsigned int getCellsNum() const;
    const sf::Color& getColor() const; 

private:
    sf::Color generateColor();
    void transformMatrixInCoordinates() const ;
};