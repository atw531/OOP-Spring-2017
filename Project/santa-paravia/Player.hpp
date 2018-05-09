#ifndef SANTA_PARAVIA_PLAYER_HPP
#define SANTA_PARAVIA_PLAYER_HPP

#include <string>
#include <cstdlib>
#include "RandomGenerator.hpp"
#include "City.hpp"

enum Gender {
    Male,
    Female
};

class Player : public City {
public:
    Player(std::string name, Gender gender, const std::string& cityName)
            : mName(std::move(name)), mGender(gender), mTitleIndex(0),
              isWinner(false), isDead(false),
              City(cityName){

        // Get the year of death
        RandomGenerator randomGenerator;
        int lifeSpan = randomGenerator.withinRange(1, 35);
        mDeathYear = 1400 + 20 + lifeSpan;
    }

    Gender getGender() { return mGender; }
    std::string getName() { return mName; }
    int getTitleIndex() { return mTitleIndex; }

    void takeTurn();
    int playerLevel() { return mTitleIndex + 1; }
    bool determineNewTitle(int difficultyLevel);
    bool checkIsDead(int currentYear);
    bool checkIsBankrupt();

private:
    std::string mName;
    Gender mGender;

    int mDeathYear;

    int mTitleIndex;

    bool isWinner;
    bool isDead;

};


#endif //SANTA_PARAVIA_PLAYER_HPP
