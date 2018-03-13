#include "Game.hpp"

int Game::getPlayerCount() {
    return mPlayerCount;
}

void Game::addPlayer(const Player& player) {
  mPlayers.push_back(player);
};