#include "PlayerStatistics.hpp"

void PlayerStatistics::addScoreByLines(int rowsNum){
    assert(rowsNum >= 0 && rowsNum <= 4 && "Can delete only 1-4 lines from field");
    if (rowsNum == 0)
        return;
    currentScore += rowsNum * 100;
    linesRemovedByOnce[rowsNum-1]++; // or at(rowsNum-1)++;
}

int PlayerStatistics::getCurrentScore() const {
    return currentScore;
}

void PlayerStatistics::addRemovedFigure(FigureType type) {
    try {
        switch (type) {
            case FigureType::Type0: numberOfRemovedFigures.at(0)++; break;
            case FigureType::Type1: numberOfRemovedFigures.at(1)++; break;
            case FigureType::Type2: numberOfRemovedFigures.at(2)++; break;
            case FigureType::Type3: numberOfRemovedFigures.at(3)++; break;
            case FigureType::Type4: numberOfRemovedFigures.at(4)++; break;
            case FigureType::Type5: numberOfRemovedFigures.at(5)++; break;
            case FigureType::Type6: numberOfRemovedFigures.at(6)++; break;

            case FigureType::NoType:
            default:
                throw std::logic_error("Incorrect type of figure in addRemovedFigure method!\n");
        }
    }
    catch (std::out_of_range){
        std::cout << "Try to increment incorrect array-index!\n";
    }
    catch (std::logic_error err){
        std::cout << err.what();
    }
}

std::ostream& operator<<(std::ostream &out, const PlayerStatistics &stats){
    std::cout << "Player statistics:\n"
              << "Score: " << stats.currentScore << "\n";
    for (std::size_t i = 0; i < stats.linesRemovedByOnce.size(); i++)
        std::cout << "\t" << i << "-lines removed: " << stats.linesRemovedByOnce[i] << "\n";
    std::cout << "Figures:\n";
    for (std::size_t i = 0; i < stats.numberOfRemovedFigures.size(); i++)
        std::cout << "\t" << i << "-type figures standed: " << stats.numberOfRemovedFigures[i] << "\n";
    std::cout << std::endl;

    return out;
}