#include "Game.hpp"

void Game::play() {
    // Start the game
    for (int i = 0; i < mPlayers.size(); i++) {
        Player* currentPlayer = mPlayers[i];
        //todo: play




        // End of turn, calculate new title
        if (currentPlayer->determineNewTitle(mDifficultyLevel)) {
            std::string tempStr = "";
            if (currentPlayer->getGender() == Male) {
                tempStr = MaleTitles[currentPlayer->getTitleIndex()];
            } else {
                tempStr = FemaleTitles[currentPlayer->getTitleIndex()];
            }

            std::cout << "Good news! You have achieved the rank of " << tempStr << "\n";
        }
    }
}