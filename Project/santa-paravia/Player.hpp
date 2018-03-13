#pragma once

#include <string>
#include "City.hpp"


enum MaleTitle {
    Sir,
    Baron,
    Count,
    Marquis,
    Duke,
    Grand_Duke,
    Prince,
    HRH_King
};

enum FemaleTitle {
    Lady,
    Baroness,
    Countess,
    Marquise,
    Duchess,
    Grand_Duchess,
    Princess,
    HRH_Queen
};

enum Gender {
    Male,
    Female
};

class Player {

public:
    Player(std::string name, Gender gender)
        : mName(name), mGender(gender) {

        if (mGender == Male) {
            mMaleTitle  = Sir;
        } else {
            mFemaleTitle = Lady;
        }

    }

private:
    std::string mName;
    Gender mGender;
    MaleTitle mMaleTitle;
    FemaleTitle mFemaleTitle;

    City mCity;
};
