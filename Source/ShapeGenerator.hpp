#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <memory>

class TetrisFigure;

class ShapeGenerator {
private:
    int currentType;
    int nextType;
    unsigned int arrayWidth;
    unsigned int arrayHeight;

public:
    static const int TypesNum = 7; //мб потом будет конфигурироваться из настроек, пока и так логично.

    ShapeGenerator(unsigned h, unsigned w);
    ~ShapeGenerator() = default;

    void generateNewShape(std::unique_ptr<TetrisFigure> &activeShape);
    
    int getNextType() const; // возвращают информацию о типах текущей и след фигур
    int getCurrType() const ; // todo

    
private:
    int generateRandomNumber();
};

#include "TetrisFigure.hpp"