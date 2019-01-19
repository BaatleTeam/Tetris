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

std::ostream& operator<<(std::ostream &out, const PlayerStatistics &stats){
    std::cout << "Player statistics:\n"
              << "Score: " << stats.currentScore << "\n";
    for (std::size_t i = 0; i < stats.linesRemovedByOnce.size(); i++)
        std::cout << i << "-lines removed: " << stats.linesRemovedByOnce[i] << "\n";
    std::cout << std::endl;

    return out;
}