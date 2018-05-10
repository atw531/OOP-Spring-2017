#ifndef SANTA_PARAVIA_GAME_HPP
#define SANTA_PARAVIA_GAME_HPP

#include <string>
#include <vector>
#include <iostream>
#include "Player.hpp"

class Game {
public:
    Game(int playerCount, int difficultyLevel)
            : mYear(1400), isWon(false) {

        if (playerCount < 1) {
            playerCount = 1;
        } else if (playerCount > 6) {
            playerCount = 6;
        }

        if (difficultyLevel < 1) {
            mDifficultyLevel = 1;
        } else if (difficultyLevel > 4) {
            mDifficultyLevel = 4;
        } else {
            mDifficultyLevel = difficultyLevel;
        }

        // Initialize each player
        for (int i = 0; i < playerCount; i++) {
            // Get the name
            std::cout << "Who is the ruler of " << CityNames[i] << "?\n";
            std::string playerName;
            std::cin >> playerName;

            // Get the gender and corresponding title
            std::cout << "Is " << playerName << " a Male or Female? (M or F)\n";
            std::string inputStr;
            Gender playerGender;
            std::cin >> inputStr;
            std::string titleStr;
            if (inputStr.at(0) == 'M' || inputStr.at(0) == 'm') {
                playerGender = Male;
                titleStr = MaleTitles[0];
            } else {
                playerGender = Female;
                titleStr = FemaleTitles[0];
            }

            // Add the player to the game
            mPlayers.emplace_back(new Player(playerName, playerGender, CityNames[i]));
        }
    }

    void play();

    void fight(Player* p1, Player* p2);

private:
    int mYear;
    bool isWon;
    int mDifficultyLevel;

    std::vector<Player*> mPlayers;

    std::vector<std::string> MaleTitles = {"Sir", "Baron", "Count", "Marquis",
                                           "Duke", "Grand Duke", "Prince", "HRH King"};
    std::vector<std::string> FemaleTitles = {"Lady", "Baroness", "Countess", "Marquise",
                                             "Duchess", "Grand Duchess", "Princess", "HRH Queen"};
    std::vector<std::string> CityNames = {"Santa Paravia", "Fiumaccio", "Torricella",
                                          "Molinetto", "Fontanile", "Romanga", "Monterana"};
};

#endif //SANTA_PARAVIA_GAME_HPP
