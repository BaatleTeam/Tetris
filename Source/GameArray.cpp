#include "GameArray.hpp"

GameArray::GameArray(const Settings &s) : height(s.getFieldSize().y + 2), width(s.getFieldSize().x) {
    ptrArray.reserve(height);
    for (int i = 0; i < height; i++)
        ptrArray.push_back(std::vector<ArrayCell>(width));
    // высота увеличивается на 2, т.к. первые двe строки выделяются по буфер
    
    activeShape = new Type0(height, width);
}

GameArray::~GameArray(){
    delete activeShape;
}

void GameArray::doStep(){
    // if (!activeShape.isActive()){
    //     displayActiveShapeOnArray();
    //     // shapeGenerator->generateNewShape(activeShape);
    // }
    removeActiveShapeFromArray();
    if (checkShapeMoving()){
        activeShape->moveDown();
    }
    else {
        // shapeGenerator->generateNewShape(activeShape);
    }
        displayActiveShapeOnArray();
}

bool GameArray::checkShapeMoving() const {
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

void GameArray::displayActiveShapeOnArray(){
    for (auto const &curShapeCoord : activeShape->getCurCoordinates())
        ptrArray[curShapeCoord.y][curShapeCoord.x].makePainted();
}

void GameArray::removeActiveShapeFromArray(){
    for (auto const &curShapeCoord : activeShape->getCurCoordinates())
        ptrArray[curShapeCoord.y][curShapeCoord.x].makeUnpainted();  
}

inline
bool GameArray::isPainted(sf::Vector2u coord) const {
    return ptrArray[coord.y][coord.x].isPainted();
}

std::ostream& operator<<(std::ostream &out, const GameArray &gmr){
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
    for (const auto &elem : gmr.activeShape->getCurCoordinates())
        out << "x = " << elem.x << " y = " <<  elem.y << "\n";
    out << "\n\n" << std::endl;
    return out;
}

// ------------------------------------------------------------------------------