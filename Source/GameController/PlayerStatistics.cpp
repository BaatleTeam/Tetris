#include "PlayerStatistics.hpp"

void PlayerStatistics::addScoreByLines(int rowsNum){
    currentScore += rowsNum * 100;
}

int PlayerStatistics::getCurrentScore() const {
    return currentScore;
}