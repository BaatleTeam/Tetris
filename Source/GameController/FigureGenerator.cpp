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
    // activeShape.reset(new TetrisFigure(currentType, arrayHeight, arrayWidth));
    activeShape.reset(new TetrisFigure(FigureType::Type0, arrayHeight, arrayWidth)); // temp only squares for testing
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