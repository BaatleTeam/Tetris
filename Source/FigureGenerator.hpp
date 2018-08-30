#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <memory>
#include "FigureTypeEnum.hpp"

class TetrisFigure;

// Отвечает за генерацию разного типа фигур, тип фигуры рандомится
// Знает тип текущей и следующей фигуры
// todo разобраться с типом фигур
class FigureGenerator {
private:
    FigureType currentType;
    FigureType nextType;
    unsigned arrayWidth;
    unsigned arrayHeight;

public:
    static const int TypesNum = 7; //мб потом будет конфигурироваться из настроек, пока и так логично.

    FigureGenerator(unsigned h, unsigned w);
    ~FigureGenerator() = default;

    void generateNew(std::unique_ptr<TetrisFigure> &activeShape);
    
    FigureType getNextType() const; // возвращают информацию о типах текущей и след фигур
    FigureType getCurrType() const ; // todo

    
private:
    FigureType generateRandomType();
};

#include "TetrisFigure.hpp"