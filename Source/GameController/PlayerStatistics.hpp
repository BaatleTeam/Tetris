


class PlayerStatistics {
private:
    int currentScore = 0;

public:
    int getCurrentScore() const;

    void addScoreByLines(int rowsNum);
};