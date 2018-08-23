#include "GameController.hpp"

GameController::GameController(const Settings &s) 
    : height(s.getFieldSize().y + 4)
    , width(s.getFieldSize().x)
    , gameField(height, width)
    , figureGenerator(height, width) 
{
    // высота увеличивается на 4, т.к. эти первые 4 строки выделяются по буфер
    // в буфере выделяются генерируются фигуры
    figureGenerator.generateNew(activeShape);
}

GameController::~GameController(){
}

void GameController::doStep(){
    removeActiveFigure();
    if (canMoveActiveFigureDown()){
        activeShape->moveDown();
        displayActiveFigure();
    }
    else {
        displayActiveFigure();
        generateNewActiveFigure();
        if (canMoveActiveFigureDown()){
            activeShape->moveDown();
            displayActiveFigure();
        }
        else {
            // game over
        }
    }
}

void GameController::generateNewActiveFigure(){
    figureGenerator.generateNew(activeShape);
}

void GameController::displayActiveFigure(){
    gameField.paintFigure(activeShape.get());
}

void GameController::removeActiveFigure(){
    gameField.unpaintFigure(activeShape.get());
}

bool GameController::canMoveActiveFigureDown() const {
    return gameField.checkFigureMoveDown(activeShape.get());
}

std::ostream& operator<<(std::ostream &out, const GameController &gmr){
    out << gmr.gameField;
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