#pragma once

#include <vector>
#include "Player.hpp"

enum Difficulty {
    Apprentice,
    Journeyman,
    Master,
    Grand_Master
};

class Game {

public:
    Game(Difficulty difficulty, int players)
        : mDifficulty(difficulty), mPlayerCount(players) {

    }

    int getPlayerCount();
    void addPlayer(const Player& player);

private:
    Difficulty mDifficulty;

    int mPlayerCount;
    std::vector<Player> mPlayers;

};
