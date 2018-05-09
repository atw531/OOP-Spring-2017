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

enum Action {

};

class Player {
public:
    Player(std::string name, Gender gender, const std::string& cityName)
            : mName(std::move(name)), mGender(gender),
              mTitleIndex(0), mLevel(1),
              isWinner(false), isDead(false) {

        // Get the year of death
        RandomGenerator randomGenerator;
        int lifeSpan = randomGenerator.withinRange(1, 35);
        mDeathYear = 1400 + 20 + lifeSpan;

        // Initialize the city
        mCity = new City(cityName);
    }

    void takeTurn();

    Gender getGender() { return mGender; }
    std::string getName() { return mName; }
    int getTitleIndex() { return mTitleIndex; }
    int getLandSize() { return mCity->getLandsize(); }
    void setLandSize(int total) { mCity->setLand(total); }
    int getSoldierCount() { return mCity->getSoldierCount(); }
    void killSoldiers(int amount) { mCity->killSoldiers(amount); }

    bool determineNewTitle(int difficultyLevel);

private:
    std::string mName;
    Gender mGender;

    City* mCity;

    int mDeathYear;

    int mTitleIndex;
    int mLevel;

    bool isWinner;
    bool isDead;

};


#endif //SANTA_PARAVIA_PLAYER_HPP
