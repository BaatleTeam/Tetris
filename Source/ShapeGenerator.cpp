#include "ShapeGenerator.hpp"

ShapeGenerator::ShapeGenerator(unsigned int h, unsigned int w)
    : arrayHeight(h), arrayWidth(w), currentType(-1), nextType(-1) {}


void ShapeGenerator::generateNewShape(ActiveShape *activeShape, char* const buf){
    unsigned int type = generateRandomNumber();
    std::cout << "Random generated;" << std::endl;
    if (currentType != -1) activeShape->~ActiveShape();
                std::cout << "type 0" << std::endl;
            activeShape = new (buf) Type0(arrayHeight, arrayWidth);
    // switch(type){
    //     case 0:
    //         std::cout << "type 0" << std::endl;
    //         activeShape = new (buf) Type0(arrayHeight, arrayWidth);
    //         break;
    //     case 1:
    //         std::cout << "type 1" << std::endl;
    //         activeShape = new (buf) Type1(arrayHeight, arrayWidth);
    //         break;
    //     default:
    //         std::cout << "real 2-6" << std::endl;
    //         activeShape = new (buf) Type1(arrayHeight, arrayWidth);
    //         break;
    // }
    currentType = type;
}

int ShapeGenerator::generateRandomNumber(){
    srand(time(NULL));
    return rand() % TypesNum;
}