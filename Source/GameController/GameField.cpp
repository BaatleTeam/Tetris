#include "GameField.hpp"

GameField::GameField(unsigned h, unsigned w) : height(h), width(w) {
    gameField.reserve(height);
    for (unsigned i = 0; i < height; i++)
        gameField.push_back(std::vector<ArrayCell>(width));
    
}

void GameField::paintFigure(const TetrisFigure *figure){
    for (auto const &curShapeCoord : figure->getCurCoordinates()){
        gameField[curShapeCoord.y][curShapeCoord.x].makePainted();
        gameField[curShapeCoord.y][curShapeCoord.x].setColor(figure->getColor());
    }
}

void GameField::unpaintFigure(const TetrisFigure *figure){
    for (auto const &curShapeCoord : figure->getCurCoordinates()){
        gameField[curShapeCoord.y][curShapeCoord.x].makeUnpainted();
        gameField[curShapeCoord.y][curShapeCoord.x].setDefaultColor();
    }
}

bool GameField::checkFigureMoveDown(const TetrisFigure *figure) const {
    try {
        for (const auto &curShapeCoord : figure->getCurCoordinates())
            if (gameField.at(curShapeCoord.y-1).at(curShapeCoord.x).isPainted())
                return false;
        return true;
    }
    catch (std::out_of_range){
        std::cout << "Catched array index out in gameArray.cpp!" << std::endl;
        return false;
    }
}

bool GameField::checkFigureMoveLeft(const TetrisFigure *figure) const {
    try {
        for (const auto &curShapeCoord : figure->getCurCoordinates())
            if (gameField.at(curShapeCoord.y).at(curShapeCoord.x-1).isPainted())
                return false;
        return true;
    }
    catch (std::out_of_range){
        std::cout << "Catched array index out in gameArray.cpp!" << std::endl;
        return false;
    }
}

bool GameField::checkFigureMoveRight(const TetrisFigure *figure) const {
    try {
        for (const auto &curShapeCoord : figure->getCurCoordinates())
            if (gameField.at(curShapeCoord.y).at(curShapeCoord.x+1).isPainted())
                return false;
        return true;
    }
    catch (std::out_of_range){
        std::cout << "Catched array index out in gameArray.cpp!" << std::endl;
        return false;
    }
}

bool GameField::checkFigureRotate(const TetrisFigure *figure) const {
    FieldCoordinates newCoord = figure->getCoordinatesAfterRotate();
    try {
        for (const auto &curShapeCoord : newCoord)
            if (gameField.at(curShapeCoord.y).at(curShapeCoord.x).isPainted())
                return false;
        return true;
    }
    catch (std::out_of_range){
        std::cout << "Catched array index out in gameArray.cpp!" << std::endl;
        return false;
    }
}

bool GameField::isCellPainted(sf::Vector2u coord) const {
    return gameField[coord.y][coord.x].isPainted();
}

sf::Color GameField::getCellColor(sf::Vector2u coord) const {
    return gameField[coord.y][coord.x].getColor();  
}


std::ostream& operator<<(std::ostream &out, const GameField &field){
    for (unsigned i = 0; i < field.height; i++){
        out << std::setw(3) << field.height - 1 - i << "| ";
        for (unsigned j = 0; j < field.width; j++)
            out << field.gameField[field.height - 1 - i][j].isPainted() << " ";
        out << "\n";
    }
    out << std::setw(4);
    out << (char)192;
    for (unsigned i = 0; i < field.width; i++)
        out  <<  "--";
    out << "\n";
    out << std::setw(6);
    for (unsigned i = 0; i < field.width; i++)
        out  << i << " ";
    out << "\n";
    return out;
}