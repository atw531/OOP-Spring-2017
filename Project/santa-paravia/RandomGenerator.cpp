#include "RandomGenerator.hpp"

int RandomGenerator::withinRange(int min, int max) {
    if (min > max) {
        int temp = min;
        min = max;
        max = temp;
    }
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

int RandomGenerator::generate() {
    std::uniform_int_distribution<uint32_t> uint_dist;
    return uint_dist(gen);
}