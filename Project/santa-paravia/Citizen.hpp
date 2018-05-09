#ifndef TEST_SANTA_CITIZEN_HPP
#define TEST_SANTA_CITIZEN_HPP

struct Citizen {
public:
    Citizen(int initialCount)
            : Count(initialCount) {

    }

    int Count;
};

struct Soldier : public Citizen {
public:
    Soldier(int initialCount, int pay)
            : Citizen(initialCount), Pay(pay) {

    }

    int Pay;
};

#endif //TEST_SANTA_CITIZEN_HPP
