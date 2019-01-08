#include "TetrisFigure.hpp"

TetrisFigure::TetrisFigure(FigureType type, int fieldHeight, int fieldWidth){
    switch (type) {
        case FigureType::Type0:
            figureMatrix = {{1,1},
                            {1,1}};
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;
        
        case FigureType::Type1:
            figureMatrix = {{0,0,0,0},
                            {1,1,1,1},
                            {0,0,0,0},
                            {0,0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 2;
            curY = fieldHeight - 3;
            break;
        
        case FigureType::Type2:
            figureMatrix = {{1,0,0},
                            {1,1,1},
                            {0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;

        case FigureType::Type3:
            figureMatrix = {{0,1,0},
                            {1,1,1},
                            {0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;

        case FigureType::Type4:
            figureMatrix = {{0,0,1},
                            {1,1,1},
                            {0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;

        case FigureType::Type5:
            figureMatrix = {{1,1,0},
                            {0,1,1},
                            {0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;
        case FigureType::Type6:
            figureMatrix = {{0,1,1},
                            {1,1,0},
                            {0,0,0}
                            };
            curX = fieldWidth / 2 - figureMatrix.size() + 1;
            curY = fieldHeight - 3;
            break;
        default:
            std::cout << "Error: undefinded type of figure in tetris figure constructor!\n";
            break;
    }
    color = generateColor();
    transformMatrixInCoordinates(figureMatrix);
}

void TetrisFigure::moveDown(){
    curY--;
}

void TetrisFigure::moveLeft(){
    curX--;
}

void TetrisFigure::moveRight(){
    curX++;
}

void TetrisFigure::rotate(){
    // std::cout << "Figure Matrix before rotate:\n";
    // for (unsigned i = 0; i <  figureMatrix.size(); i++){
    //     for (unsigned j = 0; j < figureMatrix[0].size(); j++)
    //         std::cout << figureMatrix[i][j] << " ";
    //     std::cout << "\n";
    // }

    figureMatrix = getMatrixAfterRotate();
    
    // std::cout << "Figure Matrix after rotate:\n";
    // for (unsigned i = 0; i <  figureMatrix.size(); i++){
    //     for (unsigned j = 0; j < figureMatrix[0].size(); j++)
    //         std::cout << figureMatrix[i][j] << " ";
    //     std::cout << "\n";
    // }
}

Matrix TetrisFigure::getMatrixAfterRotate() const {
    Matrix newMatrix;
    for (unsigned i = 0; i < figureMatrix[0].size(); i++){
        newMatrix.emplace_back(std::vector<int>{});
        newMatrix.back().assign(figureMatrix.size(), 0);
    }

    for (unsigned i = 0; i < figureMatrix.size(); i++){
        for (unsigned j = 0; j < figureMatrix[i].size(); j++){
            newMatrix[j][figureMatrix.size()-i-1] = figureMatrix[i][j];
        };
    };  

    return newMatrix;
}

FieldCoordinates TetrisFigure::getCoordinatesAfterRotate() const {
    return std::move(transformMatrixInCoordinates(getMatrixAfterRotate()));
}

const Matrix& TetrisFigure::getFigureMatrix() const {
    return figureMatrix;
}

FieldCoordinates TetrisFigure::getCurCoordinates() const {
    coordinates.clear();
    coordinates = transformMatrixInCoordinates(figureMatrix);
    return coordinates;
}

unsigned int TetrisFigure::getCellsNum() const {
    return coordinates.size();
}

const sf::Color& TetrisFigure::getColor() const {
    return color;
}

sf::Color TetrisFigure::generateColor(){
    unsigned r, g, b;
    do {
        r = rand() % 2;
        g = rand() % 2;
        b = rand() % 2;
    }
    while ((r + g + b) == 0 || (r + g + b) == 3); // neither white nor black
    return sf::Color(r * 255, g * 255, b * 255);
}

FieldCoordinates TetrisFigure::transformMatrixInCoordinates(const Matrix& matrix) const {
    FieldCoordinates newCoord{};
    unsigned currRow = 0;
    for (const auto &row: matrix){
        unsigned currCol = 0;
        for (const auto &cell: row){
            if (cell != 0){
                // std::cout << "Conversation in getCurCoord: " << curX << " " << currCol << " " << curY << " " << currRow << "\n";
                newCoord.push_back({curX + currCol, curY - currRow});
            }
            currCol++;
        }
        currRow++;
    }
    return newCoord;
}