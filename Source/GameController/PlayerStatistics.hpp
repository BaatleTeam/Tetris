
// struct NumLinesRemovedOnce {
//     unsigned one = 0;
//     unsigned two = 0;
//     unsigned three = 0;
//     unsigned four = 0;
// };
#include <array>
#include <cassert>
#include <iostream>

class PlayerStatistics {
private:
    int currentScore = 0;
    std::array <unsigned, 4> linesRemovedByOnce = {0,0,0,0};

public:
    PlayerStatistics() = default;

    int getCurrentScore() const;

    void addScoreByLines(int rowsNum);

    friend std::ostream& operator<<(std::ostream &out, const PlayerStatistics &stats);
};

