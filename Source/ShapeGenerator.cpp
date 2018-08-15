#include "GameArray.hpp"

ShapeGenerator::ShapeGenerator(unsigned int h, unsigned int w)
    : arrayHeight(h), arrayWidth(w), currentType(-1), nextType(-1) {}


void ShapeGenerator::generateNewShape(std::unique_ptr<ActiveShape> &activeShape){
    unsigned int type = generateRandomNumber();
    switch(type){
        case 0:
            activeShape.reset(new Type0(arrayHeight, arrayWidth));
            break;
        case 1:
            activeShape.reset(new Type1(arrayHeight, arrayWidth));
            break;
        case 2:
            activeShape.reset(new Type2(arrayHeight, arrayWidth));
            break;
        // case 3:
        //     activeShape.reset(new Type3(arrayHeight, arrayWidth));
        //     break;
        // case 4:
        //     activeShape.reset(new Type4(arrayHeight, arrayWidth));
        //     break;
        // case 5:
        //     activeShape.reset(new Type5(arrayHeight, arrayWidth));
        //     break;
        // case 6:
        //     activeShape.reset(new Type6(arrayHeight, arrayWidth));
        //     break;
        default:
            throw "Generated non-registred shape type\n";
    }
    currentType = type;
}

int ShapeGenerator::generateRandomNumber(){
    srand(time(NULL));
    return rand() % TypesNum;
}