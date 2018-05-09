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

struct Serf : public Citizen {
public:
    Serf(int initialCount)
            : Citizen(initialCount),
              New(0), Dead(0), Transplanted(0), Fleeing(0) {

    }

    int New;
    int Dead;
    int Transplanted;
    int Fleeing;
};

#endif //TEST_SANTA_CITIZEN_HPP
