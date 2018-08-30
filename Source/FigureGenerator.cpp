#include "FigureGenerator.hpp"

FigureGenerator::FigureGenerator(unsigned int h, unsigned int w)
    : arrayHeight(h)
    , arrayWidth(w)
    , currentType(FigureType::NoType)
    , nextType(FigureType::NoType)
{

}

void FigureGenerator::generateNew(std::unique_ptr<TetrisFigure> &activeShape){
    if (nextType != FigureType::NoType)
        currentType = nextType;
    else
        currentType = generateRandomType();
    
    nextType = generateRandomType();
    switch(currentType){
        case FigureType::Type0:
            activeShape.reset(new Type0(arrayHeight, arrayWidth));
            break;
        case FigureType::Type1:
            activeShape.reset(new Type1(arrayHeight, arrayWidth));
            break;
        case FigureType::Type2:
            activeShape.reset(new Type2(arrayHeight, arrayWidth));
            break;
        case FigureType::Type3:
            activeShape.reset(new Type3(arrayHeight, arrayWidth));
            break;
        case FigureType::Type4:
            activeShape.reset(new Type4(arrayHeight, arrayWidth));
            break;
        case FigureType::Type5:
            activeShape.reset(new Type5(arrayHeight, arrayWidth));
            break;
        case FigureType::Type6:
            activeShape.reset(new Type6(arrayHeight, arrayWidth));
            break;
        default:
            throw "Generated non-registred shape type!";
    }
}

FigureType FigureGenerator::generateRandomType(){
    srand(time(NULL));
    return static_cast<FigureType>((rand() % TypesNum) + 1 ); // 0 is NoType type
}

FigureType FigureGenerator::getCurrType() const {
    return currentType;
}

FigureType FigureGenerator::getNextType() const {
    return nextType;
}