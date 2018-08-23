#include "GameController.hpp"

GameController::GameController(const Settings &s) 
    : height(s.getFieldSize().y + 4)
    , width(s.getFieldSize().x)
    , figureGenerator(height, width) 
{
    ptrArray.reserve(height);
    for (int i = 0; i < height; i++)
        ptrArray.push_back(std::vector<ArrayCell>(width));
    // высота увеличивается на 4, т.к. эти первые 4 строки выделяются по буфер
    // в буфере выделяются генерируются фигуры
    figureGenerator.generateNewShape(activeShape);
}

GameController::~GameController(){
}

void GameController::doStep(){
    removeActiveShapeFromArray();
    if (checkShapeMoving()){
        activeShape->moveDown();
        displayActiveShapeOnArray();
    }
    else {
        displayActiveShapeOnArray();
        figureGenerator.generateNewShape(activeShape);
        if (checkShapeMoving()){
            activeShape->moveDown();
            displayActiveShapeOnArray();
        }
        else {
            // game over
        }
    }
}

bool GameController::checkShapeMoving() const {
    try {
        for (const auto &curShapeCoord : activeShape->getCurCoordinates())
            if (ptrArray.at(curShapeCoord.y-1).at(curShapeCoord.x).isPainted())
                return false;
        return true;
    }
    catch (std::out_of_range){
        std::cout << "Ura, raboraet!" << std::endl;
        return false;
    }
}

void GameController::displayActiveShapeOnArray(){
    for (auto const &curShapeCoord : activeShape->getCurCoordinates())
        ptrArray[curShapeCoord.y][curShapeCoord.x].makePainted();
}

void GameController::removeActiveShapeFromArray(){
    for (auto const &curShapeCoord : activeShape->getCurCoordinates()){
        ptrArray[curShapeCoord.y][curShapeCoord.x].makeUnpainted();  
    }
}

bool GameController::isPainted(sf::Vector2u coord) const {
    return ptrArray[coord.y][coord.x].isPainted();
}

std::ostream& operator<<(std::ostream &out, const GameController &gmr){
    for (int i = 0; i < gmr.height; i++){
        out << std::setw(3) << gmr.height -1 - i << "| ";
        for (int j = 0; j < gmr.width; j++)
            out << gmr.ptrArray[gmr.height -1 - i][j].isPainted() << " ";
        out << "\n";
    }
    out << std::setw(4);
    out << (char)192;
    for (int i = 0; i < gmr.width; i++)
        out  <<  "--";
    out << "\n";
    out << std::setw(6);
    for (int i = 0; i < gmr.width; i++)
        out  << i << " ";
    out << "\n";
    #define COLOR gmr.activeShape.get()->getColor()
    std::cout << "Color (rgb): " << (int)COLOR.r << " " << (int)COLOR.g << " " << (int)COLOR.b << "\n";
    for (const auto &elem : gmr.activeShape->getCurCoordinates())
        out << "x = " << elem.x << " y = " <<  elem.y << "\n";
    out << "Current type: " << gmr.figureGenerator.getCurrType() << "\n";
    out << "Next type: " << gmr.figureGenerator.getNextType() << "\n";
    out << "\n\n" << std::endl;
    return out;
}

// ------------------------------------------------------------------------------