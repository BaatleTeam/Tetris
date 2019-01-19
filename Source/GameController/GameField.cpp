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

int GameField::removeFilledLines(){
    int number = 0;
    for (unsigned i = height; i > 0; i--){ // i-1 due to unsigned type overflow when loop check "i = 0--"
        bool isRowFilled = checkLineFilled(i-1);
        std::cout << "Check row number " << i-1 << ". Result: " << isRowFilled << "\n";
        if (isRowFilled){
            number++;
            clearRow(i-1);
        }
    }
    return number;
}




bool GameField::checkLineFilled(unsigned row) const {
    unsigned filledCellsInRow = 0;
    
    for (unsigned col = 0; col < width; col++)
        if (gameField[row][col].isPainted())
            filledCellsInRow++;
    
    return (filledCellsInRow == width) ? true : false;
    
}

void GameField::clearRow(unsigned row) {
    for (unsigned i = row; i < height-1; i++){
        std::swap(gameField[i], gameField[i+1]);
    }
    for (unsigned j = 0; j < width; j++)
        gameField[height-1][j].makeUnpainted();
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