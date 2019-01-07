#pragma once
#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>
#include "GameField.hpp"
#include "../FigureTypeEnum.hpp"

class GameField;

// Базовый класс для различных типов фигур
// Хранит координаты каждой клеточки фигуры и кол-во вариантов поворота
using Matrix = std::vector<std::vector <int>>;
using FieldCoordinates = std::vector <sf::Vector2u>;

class TetrisFigure {
private:
    unsigned curX;
    unsigned curY;
    Matrix figureMatrix;
    sf::Color color;
    mutable FieldCoordinates coordinates;

public:
    TetrisFigure(FigureType type, int fieldHeight, int fieldWidth);
    TetrisFigure() = delete;
    virtual ~TetrisFigure() = default;

    void moveDown();
    void moveLeft();
    void moveRight();
    void rotate();

    Matrix getMatrixAfterRotate() const;
    
    FieldCoordinates getCoordinatesAfterRotate() const;
    FieldCoordinates getCurCoordinates() const;
    const Matrix& getFigureMatrix() const;
    unsigned int getCellsNum() const;
    const sf::Color& getColor() const; 

private:
    sf::Color generateColor();
    FieldCoordinates transformMatrixInCoordinates(const Matrix& matrix) const ;
};