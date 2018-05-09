#include <iostream>
#include "Game.hpp"

void printInstructions();

int main() {
    std::cout << "Welcome to Santa Paravia and Fiumaccio\n";
    std::cout << "Would you like to see the instructions? (Y or N)";
    std::string input;
    std::cin >> input;
    if (std::tolower(input.front()) == 'y') {
        printInstructions();
    }

    std::cout << "How many people want to play (1 to 6)?\n";
    int playerCount = 0;
    std::cin >> playerCount;
    if (playerCount < 1 || playerCount > 6) {
        std::cout << "Thanks for playing.\n";
        return 0;
    }

    std::cout << "What will be the difficulty fo the game:\n";
    std::cout << "1. Apprentice\n2. Journeyman\n3. Master\n4. Grand Master\n\nChoose: ";
    int difficulty = 1;
    std::cin >> difficulty;

    Game* theGame = new Game(playerCount, difficulty);

    return 0;
}

void printInstructions() {

    std::cout << "Santa Paravia and Fiumaccio\n\n";
    std::cout << "You are the ruler of a 15th century Italian city state.\n";
    std::cout << "If you rule well, you will receive higher titles. The\n";
    std::cout << "first player to become king or queen wins. Life expectancy\n";
    std::cout << "then was brief, so you may not live long enough to win.\n";
    std::cout << "The computer will draw a map of your state. The size\n";
    std::cout << "of the area in the wall grows as you buy more land. The\n";
    std::cout << "size of the guard tower in the upper left corner shows\n";
    std::cout << "the adequacy of your defenses. If it shrinks, equip more\n";
    std::cout << "soldiers! If the horse and plowman is touching the top of the wall,\n";
    std::cout << "all your land is in production. Otherwise you need more\n";
    std::cout << "serfs, who will migrate to your state if you distribute\n";
    std::cout << "more grain than the minimum demand. If you distribute less\n";
    std::cout << "grain, some of your people will starve, and you will have\n";
    std::cout << "a high death rate. High taxes raise money, but slow down\n";
    std::cout << "economic growth. (Press ENTER to begin game)\n";

    std::cin.get();

}