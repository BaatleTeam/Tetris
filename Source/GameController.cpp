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

};

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

void GameController::moveFigureLeft(){
    removeActiveFigure();
    if (gameField.checkFigureMoveLeft(activeShape.get()))
        activeShape->moveLeft();
    displayActiveFigure();
}

void GameController::moveFigureRight(){
    removeActiveFigure();
    if (gameField.checkFigureMoveRight(activeShape.get()))
        activeShape->moveRight();
    displayActiveFigure();
}

void GameController::rotateFigure(){
    removeActiveFigure();
    activeShape->rotate(gameField);
    displayActiveFigure();
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

std::ostream& operator<<(std::ostream &out, const GameController &gc){
    out << gc.gameField;
    #define COLOR gc.activeShape.get()->getColor()
    std::cout << "Color (rgb): " << (int)COLOR.r << " " << (int)COLOR.g << " " << (int)COLOR.b << "\n";
    for (const auto &elem : gc.activeShape->getCurCoordinates())
        out << "x = " << elem.x << " y = " <<  elem.y << "\n";
    out << "Current type: " << gc.figureGenerator.getCurrType() << "\n";
    out << "Next type: " << gc.figureGenerator.getNextType() << "\n";
    out << "\n\n" << std::endl;
    return out;
}

// ------------------------------------------------------------------------------