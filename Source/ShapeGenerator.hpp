#pragma once
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <memory>

class ActiveShape;

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

    void generateNewShape(std::unique_ptr<ActiveShape> &activeShape);

    
private:
    int generateRandomNumber();
};

#include "ActiveShape.hpp"