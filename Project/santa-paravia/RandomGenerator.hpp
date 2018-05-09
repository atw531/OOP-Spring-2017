#ifndef SANTA_PARAVIA_RANDOMGENERATOR_HPP
#define SANTA_PARAVIA_RANDOMGENERATOR_HPP

#include <random>

class RandomGenerator {

public:
    RandomGenerator() {
        // Seed the random generator
        gen.seed(rd());
    }

    int withinRange(int min, int max);

    int generate();

private:
    std::random_device rd;
    std::mt19937 gen;
};


#endif //SANTA_PARAVIA_RANDOMGENERATOR_HPP
