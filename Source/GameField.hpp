#pragma once
#include <vector>
#include <iostream>
#include <iomanip>
#include <SFML/System/Vector2.hpp>
#include "ArrayCell.hpp"
#include "TetrisFigure.hpp"

class TetrisFigure;

class GameField {
private:
    unsigned width; 
    unsigned height;
    std::vector <std::vector <ArrayCell> > gameField; // выделить поле в отдельный класс? думаю, да

public:
    GameField(unsigned height, unsigned width);

    void paintFigure(const TetrisFigure *figure);
    void unpaintFigure(const TetrisFigure *figure);
    bool checkFigureMoveDown(const TetrisFigure *figure) const;
    bool isCellPainted(sf::Vector2u coord) const;


    friend std::ostream& operator<<(std::ostream &out, const GameField &fied);
};